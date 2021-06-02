/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <map>
#include "model/objet/Measurement.h"
#include "model/objet/Attribute.h"
#include "model/objet/Sensor.h"
#include "model/objet/Individual.h"
#include "model/objet/Provider.h"
#include "model/objet/Agency.h"
using namespace std;

//------------------------------------------------------ Include personnel
#include "Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Service::afficheVerification(){
    cout << endl << endl << "<<------------------------------------------->>" << endl << endl ;
    afficheSensors() ;
    cout << endl << endl << "<<------------------------------------------->>" << endl << endl ;
    afficheMeasurements() ;
    cout << endl << endl << "<<------------------------------------------->>" << endl << endl ;
}

Sensor * Service::getSensorByID(const string & sensorID){
	list<Sensor*>::iterator currentSensor;
	
	for(currentSensor=sensors.begin();currentSensor!=sensors.end();currentSensor++){
		if((*currentSensor)->getID()==sensorID){
			return(*currentSensor);
		}
	}
	return(nullptr);
}

User * Service::authentifier(const string & id, const string & mdp){
	list<User*>::iterator currentUser;
	for(currentUser=users.begin();currentUser!=users.end();currentUser++){
		if((*currentUser)->isEqual(id,  mdp)){
			return *currentUser;
		}
	}
	return(nullptr);
}

string Service :: checkSensor (string idAtester) {

    //currentSensor est le Sensor qu'on va verifier et compared va être ceux qu'on va utiliser comme référence
    list<Sensor*>::iterator currentSensor;
    list<Sensor*>::iterator comparedSensor;
    
    //pour chacun des 4 types de mesures, on initialise des seuils au dessus desquels les mesures ne sont plus valides
    //chaque colonne correspond à un type de mesure (O3, NO2, SO2 puis PM10)
    int const tailleTab (4) ;
    double distanceSeuil = 50.0 ; //distance maximale pour qu'un capteur soit pris en compte pour la validite de proximité
    double seuilsProximite [tailleTab] = { 10.0, 10.0, 10.0, 10.0 }; //il ne faut pas que le capteur soit plus eloigné de ces valeurs des moyennes dans son rayon geographique
    double seuilsDerivees [tailleTab] = { 10.0, 10.0, 10.0, 10.0 }; //il ne faut pas que les valeurs du capteur different entre elles de plus que ces seuils
    
    double moyenne [tailleTab] = { 0, 0, 0, 0 }; //moyenne des mesures des capteurs dans le rayon seuil

    for(currentSensor=sensors.begin(); currentSensor!=sensors.end(); currentSensor++)
    { //on parcourt la liste des capteurs jusqu'à trouver le bon
        if((*currentSensor)->getID() == idAtester && (*currentSensor)->isValid() != "unchecked"){ //si le capteur a déjà été vérifié, pas besoin de tout recalculer, on renvoie directement sa validité
            return (*currentSensor)->isValid() ;
        } else if((*currentSensor)->getID() == idAtester) { //si le capteur n'a pas encore ete verifie, on va lancer la procedure de verification
            int nbSensorsProches = 0 ;
            Point currentLocation = (*currentSensor)->getLocation();
            for(comparedSensor=sensors.begin(); comparedSensor!=sensors.end(); comparedSensor++)
            {//on va reparcourir toute la liste de capteurs pour etre prendre en compte ceux dans le rayon du capteur demandé
                double distance = (*comparedSensor)->getLocation().getDistance(currentLocation);
                if(distance > 0 && distance <= distanceSeuil){
                    if((*comparedSensor)->getLastValue("O3") == -1 || (*comparedSensor)->getLastValue("NO2") == -1 || (*comparedSensor)->getLastValue("SO2") == -1 || (*comparedSensor)->getLastValue("PM10") == -1 ){//si jamais un des attributs du capteur comparé n'est pas présent dans les mesures (égal à -1)
                        cerr << "Problème dans la methode checkSensors dans la partie proximité : attribut inexistant" << endl ;
                        break ;
                    }
                    //si les mesures sont bien initialisees (differentes de -1), on les ajoute eux moyennes et on incremente le nombre de capteurs pris en compte
                    moyenne[0] += (*comparedSensor)->getLastValue("O3") ;
                    moyenne[1] += (*comparedSensor)->getLastValue("NO2") ;
                    moyenne[2] += (*comparedSensor)->getLastValue("SO2") ;
                    moyenne[3] += (*comparedSensor)->getLastValue("PM10") ;
                    nbSensorsProches ++ ;
                }
            }
            
            bool validiteProximite = true ;
            
            string titres [tailleTab] = {"O3", "NO2", "SO2", "PM10"} ;
            
            //pour chacune des moyennes, on va verifier l'ecart à la valeur du capteur
            for(int i = 0 ; i < tailleTab ; i++ ){
                if(nbSensorsProches != 0){
                    moyenne[i] /= nbSensorsProches ; //on divise pour avoir la moyenne et pas la somme
                    if(abs(moyenne[i] - (*currentSensor) -> getLastValue(titres[i])) > seuilsProximite[i]){ // si la difference est superieure au seuil, le capteur n'est pas valide par rapport à son entourage
                        validiteProximite = false ;
                        break ;
                    }
                } //else if nbSensorsProches==0, du coup la validite geographique reste à true
            }
            
            
            //on va maintenant parcourir toutes les mesures du capteur pour voir s'il n'y a pas de trop grand saut à un moment
            //onva donc avoir des mesures actuelles et precedentes, ainsi que leur difference
            double precedentValues [tailleTab] ;
            double currentValues [tailleTab] ;
            double maxDifferences [tailleTab] ;
            
            for(int i(0); i<tailleTab; i++)
            { //on initialise les valeursPrecedentes à -1 et les differences à 0
                precedentValues[i] = -1 ;
                maxDifferences[i] = 0 ;
            }
            
            list<Measurement>::const_iterator currentMeasurement ;
            bool mesuresValides = true ;
            
            for(currentMeasurement=(*currentSensor)->getMesures().begin() ; currentMeasurement!=(*currentSensor)->getMesures().end() ; currentMeasurement++)
            {
                int typeMesure (-1) ; //correspond au type de la mesure actuellement parcourue, on a 0 pour O3, 1 pour NO2, 2 pour SO2 et 3 pour PM10
                string type = currentMeasurement->getAttribute().getID() ;
                
                if(type == "O3"){
                    typeMesure = 0 ;
                } else if(type == "NO2"){
                    typeMesure = 1 ;
                } else if(type == "SO2"){
                    typeMesure = 2 ;
                } else if(type == "PM10"){
                    typeMesure = 3 ;
                }
                
                if(typeMesure == -1){ //si typeMesure vaut toujours sa valeur d'initialisation, ca veut dire que le type n'est pas reconnu et la mesure n'est pas valide
                    mesuresValides = false ;
                    break ;
                }
                
                if(precedentValues[typeMesure] == -1){ //si le tableau n'est pas encore initialisé (premier parcours de la boucle)
                    precedentValues[typeMesure] = currentMeasurement->getValue() ;
                    currentValues[typeMesure] = currentMeasurement->getValue() ;
                } else { //si le tableau est deja initialisé, on peut comparer la valeur actuelle à la valeur précédente (du meme type)
                    precedentValues[typeMesure] = currentValues[typeMesure] ;
                    currentValues[typeMesure] = currentMeasurement->getValue() ;
                    double difference = currentValues[typeMesure]-precedentValues[typeMesure] ;
                    maxDifferences[typeMesure] = max(maxDifferences[typeMesure], abs(difference)) ;
                }
            }
            
            bool validiteDerivee = true ;
            
            //si les mesures ne sont pas valides ou qu'une difference excède le seuil, la validité par rapport à la constance des mesures est fausse
            if(!mesuresValides){
                validiteDerivee = false ;
            } else {
                for(int i(0); i<tailleTab; i++){
                    if(maxDifferences[i] > seuilsDerivees[i]){ //la difference est toujours positive donc pas besoin de verifier la valeur absolue
                        validiteDerivee = false ;
                        break ;
                    }
                }
            }
            
            //si le capteur a deux validites, il est valide, s'il a deux invalidites, il est invalide, sinon il est incertain
            if(validiteProximite && validiteDerivee){
                (*currentSensor)->setValid("valide") ;
            } else if(!validiteProximite && !validiteDerivee){
                (*currentSensor)->setValid("defectueux") ;
            } else {
                (*currentSensor)->setValid("incertain") ;
            }
            return (*currentSensor)->isValid() ;
        }
    }
    return "sensor not found" ; //si on n'est pas sorti dans la boucle, ca veut dire que l'id du capteur n'a pas ete trouvé dans la liste
}

pair<map<Attribute, double>, double> Service :: MesurerPerformancePurificateur (string & cleaner_id) {
    Cleaner* cl = findCleaner(cleaner_id);
    double distance_max = 0.0f;
    map<Attribute, double> moyenne_ecarts;
    
    if (cl!=nullptr){ // Un cleaner avec cet ID
    
	    double seuil = 0.0f;
	    map<Attribute, pair<double, int>> total_ecarts;
	    
	    // On trie les Sensors en fonction de la distance du Cleaner
	    sortByDistance(cl->getLocation());
	    
	    list<Sensor*>::iterator currentSensor;
	    // Pour chaque sensor en fonction de la distance
	    for(currentSensor=sensors.begin(); currentSensor!=sensors.end(); currentSensor++)
	    {
	    	map<Attribute, double> ecart_courant;
	    	// On calcule le pourcentage d'amélioration de chaque attribut
	    	calculerPourcentageAttributs(ecart_courant, **currentSensor, cl->getStart(), cl->getStop());
	    	
	    	if (estEfficace(ecart_courant, seuil)) {
	    		// Si le capteur est efficace, on ajoute au total des écarts les écarts de chaque attribut (pour calcul de moyenne)
	    		map<Attribute,double>::iterator it;
	    		for(it=ecart_courant.begin(); it!=ecart_courant.end(); it++)
			{
				Attribute a = it->first;
				double total = 0.0f;
				int nombre = 0;
				map<Attribute,pair<double, int>>::iterator val = total_ecarts.find(a);
				if (val!=total_ecarts.end()) {
					total = val->second.first;
					nombre = val->second.second;
					total_ecarts.erase(val);
				}
				total += it->second;
				++nombre;
				total_ecarts.insert(make_pair(a, make_pair(total, nombre)));
			}
	    		// Puis on met à jour le rayon d'action
			distance_max = (*currentSensor) -> getLocation().getDistance(cl->getLocation());
	    		//cout << (*currentSensor)->getID() << " " << distance_max << endl;
	    	} else {
	    		// Sinon on arrête
	    		break;
	    	}
	    }
	    map<Attribute,pair<double, int>>::iterator it;
	    // On calcule la moyenne des écarts pour chaque attribut
	    for(it=total_ecarts.begin(); it!=total_ecarts.end(); it++)
	    {
	    	Attribute a = it->first;
		double total = it->second.first;
		int nombre = it->second.second;
		moyenne_ecarts.insert(make_pair(a, total/nombre));
	    }
	    //cout << distance_max << endl;
    } else {
    	    // Pas de Cleaner = distance négative
	    distance_max = -1.0f;
    }
    // On renvoie les moyennes et le rayon d'action
    return make_pair(moyenne_ecarts, distance_max);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Service::Service ( const Service & unService )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service>" << endl;
#endif
} //----- Fin de Service (constructeur de copie)


Service::Service (string csv_attributes, string csv_cleaners, string csv_measurements, string csv_providers, string csv_sensors, string csv_users)
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
    readSensors(csv_attributes, csv_measurements, csv_sensors);
    // TODO: Read users, providers and cleaners
    readCleaners(csv_cleaners);
    readUsers(csv_users, csv_providers);
} //----- Fin de Service


Service::~Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Service>" << endl;
#endif
    list<Sensor*>::iterator currentSensor;
    
    for(currentSensor=sensors.begin(); currentSensor!=sensors.end(); currentSensor++)
    {
    	delete *currentSensor;
    }
    
    list<Cleaner*>::iterator currentCleaner;
    
    for(currentCleaner=cleaners.begin(); currentCleaner!=cleaners.end(); currentCleaner++)
    {
    	delete *currentCleaner;
    }
    
    list<User*>::iterator currentUser;
    
    for(currentUser=users.begin(); currentUser!=users.end(); currentUser++)
    {
    	delete *currentUser;
    }
        
} //----- Fin de ~Service


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Service::afficheSensors(){
    cout << "Liste des Sensors :" << endl ;
    list<Sensor*>::iterator comparedSensor;
    for(comparedSensor=sensors.begin(); comparedSensor!=sensors.end(); comparedSensor++){
        cout << "\t --> id:" << (*comparedSensor)->getID() << " ; location:(" << (*comparedSensor)->getLocation().getLatitude() <<", " << (*comparedSensor)->getLocation().getLongitude() << ") ; isValid:" << (*comparedSensor)->isValid() << endl ;
    }
}

void Service::afficheMeasurements(){
    cout << "Liste des Measurements :" << endl ;
    list<Sensor*>::iterator comparedSensor;
    for(comparedSensor=sensors.begin(); comparedSensor!=sensors.end(); comparedSensor++){
        cout << "\t --> id:" << (*comparedSensor)->getID() << endl ;
        list<Measurement>::const_iterator currentMeasurement ;
        
        for(currentMeasurement=(*comparedSensor)->getMesures().begin() ; currentMeasurement!=(*comparedSensor)->getMesures().end() ; currentMeasurement++)
        {
            cout << "\t\t --> value:" << currentMeasurement->getValue() << " ; attribut:" << currentMeasurement->getAttribute().getID() << endl ;
        }
    }
    
}

Cleaner* Service::findCleaner(const string & cleaner_id) {
	list<Cleaner*>::iterator it;
	for(it=cleaners.begin();it!=cleaners.end();it++){
		if ((*it)->getID()==cleaner_id) {
			return (*it);
		}
	}
	return nullptr;
}

void Service::sortByDistance(const Point & location) {

	sensors.sort([location](const Sensor* a, const Sensor* b) {
		double dist_a = location.getDistance(a->getLocation());
		double dist_b = location.getDistance(b->getLocation());
		return dist_a <= dist_b;
	});
	
}

void Service::calculerPourcentageAttributs(map<Attribute, double> & pourcentages, const Sensor & s, const Date & debut, const Date & fin) {
	map<Attribute, pair<Date, double>> val_debut;
	map<Attribute, pair<Date, double>> val_fin;
	
	list<Measurement>::const_iterator it;
	map<Attribute,pair<Date, double>>::iterator it_deb;
	map<Attribute,pair<Date, double>>::iterator it_fin;
	// On cherche les mesures des capteurs les plus proches du début et de la fin de mise en service du capteur
	for(it=s.getMesures().begin();it!=s.getMesures().end();it++){
		// On regarde les mesures les plus proches avant le début de mise en service du capteur
		if (debut>=it->getDate()) {
			bool ok_insert = true;
			it_deb = val_debut.find(it->getAttribute());
			if (it_deb!=val_debut.end()) {
				if (it_deb->second.first>=it->getDate()) {
					ok_insert = false;
				} else {
					val_debut.erase(it_deb);
				}
			}
			// On remplace si on trouve plus proche
			if (ok_insert) {
				val_debut.insert(make_pair(it->getAttribute(), make_pair(it->getDate(), it->getValue())));
			}
		}
		// On regarde les mesures les plus proches avant la fin de mise en service du capteur
		if (fin>=it->getDate()) {
			bool ok_insert = true;
			it_fin = val_fin.find(it->getAttribute());
			if (it_fin!=val_fin.end()) {
				if (it_fin->second.first>=it->getDate()) {
					ok_insert = false;
				} else {
					val_fin.erase(it_fin);
				}
			}
			// On remplace si on trouve plus proche
			if (ok_insert) {
				val_fin.insert(make_pair(it->getAttribute(), make_pair(it->getDate(), it->getValue())));
			}
		}
	}
	
	// On calcule les améliorations pour chaque attribut
	for(it_deb=val_debut.begin();it_deb!=val_debut.end();it_deb++){
		it_fin = val_fin.find(it_deb->first);
		if (it_fin!=val_fin.end()) {
			pourcentages.insert(make_pair(it_deb->first, (it_deb->second.second-it_fin->second.second)/it_deb->second.second));
		}
	}
}

bool Service::estEfficace(const map<Attribute, double> & ecart_courant, double seuil) {
	map<Attribute,double>::const_iterator it;
	double total = 0;
	int nombre = 0;
	for(it=ecart_courant.begin();it!=ecart_courant.end();it++){
		total += it->second;
		++nombre;
	}
	// On fait la moyenne des écarts de tous les attributs puis on vérifie la plus proche
	return total/nombre>=seuil;
}

// FONCTIONS DE LECTURE DE CSV

Date Service::readDate(ifstream& ifs) {
	string buffer;
	int a,m,j,h,mi,s;
	getline(ifs, buffer, '-');
	a = stoi(buffer);
	getline(ifs, buffer, '-');
	m = stoi(buffer);
	getline(ifs, buffer, ' ');
	j = stoi(buffer);
	getline(ifs, buffer, ':');
	h = stoi(buffer);
	getline(ifs, buffer, ':');
	mi = stoi(buffer);
	getline(ifs, buffer, ';');
	s = stoi(buffer);
	return Date(a,m,j,h,mi,s);
}

void Service::readSensors(string& csv_attributes, string& csv_measurements, string& csv_sensors) {
    ifstream in_attr;
    string buffer;
    char c;
    in_attr.open(csv_attributes);
    map<string, Attribute> attributes;
    if( ! in_attr.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_attributes << ">" << endl;
    } else {
        while (!in_attr.eof()) {
        	string id;
        	string unit;
        	string description;
        	getline(in_attr, id, ';');
        	getline(in_attr, unit, ';');
        	getline(in_attr, description, ';');
        	
        	//Ignore everything until the end of the line
        	getline(in_attr, buffer, '\n');
        	Attribute a(id);
        	attributes.insert(pair<string,Attribute>(id, a));
        	in_attr.get(c);
        	if (in_attr.eof()) {
        		break;
        	}
        	in_attr.seekg(-1, ios_base::cur);
        }
        in_attr.close();
    }
    ifstream in_meas;
    in_meas.open(csv_measurements);
    multimap<string, Measurement> measurements;
    if( ! in_meas.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_measurements << ">" << endl;
    } else {
        while (!in_meas.eof()) {
        	Date date = readDate(in_meas);
        	string sensor_id;
        	string attrib_id;
        	string value;
        	getline(in_meas, sensor_id, ';');
        	getline(in_meas, attrib_id, ';');
        	//Ignore everything until the end of the line
        	getline(in_meas, value, ';');
        	getline(in_meas, buffer, '\n');
        	Measurement m(date, attributes.find(attrib_id)->second, stod(value));
        	measurements.insert(pair<string,Measurement>(sensor_id, m));
        	in_meas.get(c);
        	if (in_meas.eof()) {
        		break;
        	}
        	in_meas.seekg(-1, ios_base::cur);
        }
        in_meas.close();
    }
    ifstream in_sens;
    in_sens.open(csv_sensors);
    if( ! in_sens.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_sensors << ">" << endl;
    } else {
        while (!in_sens.eof()) {
        	string sensor_id;
        	string lat;
        	string lon;
        	string buffer ;
        	getline(in_sens, sensor_id, ';');
        	getline(in_sens, lat, ';');
        	getline(in_sens, lon, ';');
        	//Ignore everything until the end of the line
        	getline(in_sens, buffer, '\n');
        	
        	list<Measurement> ms;
        	multimap<string,Measurement>::const_iterator it;
        	for(it=measurements.lower_bound(sensor_id);it!=measurements.upper_bound(sensor_id);it++){
			ms.push_back(it->second);
		}
		
		//Trier les mesures par date
		ms.sort([](const Measurement & a, const Measurement & b) {
			Date date_a = a.getDate();
			Date date_b = b.getDate();
			return date_a <= date_b;
		});
		Sensor* s = new Sensor(sensor_id, Point(stod(lat), stod(lon)),"unchecked", ms);
        	sensors.push_back(s);
        	in_sens.get(c);
        	if (in_sens.eof()) {
        		break;
        	}
        	in_sens.seekg(-1, ios_base::cur);
        }
        in_sens.close();
    }
}

void Service::readCleaners(string& csv_cleaners) {
    ifstream in_clean;
    string buffer;
    char c;
    in_clean.open(csv_cleaners);
    if( ! in_clean.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_cleaners << ">" << endl;
    } else {
        while (!in_clean.eof()) {
        	string id;
        	string sensor_id;
        	string lat;
        	string lon;
        	getline(in_clean, id, ';');
        	getline(in_clean, lat, ';');
        	getline(in_clean, lon, ';');
        	Date start = readDate(in_clean);
        	Date stop = readDate(in_clean);
        	//Ignore everything until the end of the line
        	getline(in_clean, buffer, '\n');
        	list<Sensor*>::iterator it;
        	Cleaner* cl = new Cleaner(id, nullptr, Point(stod(lat), stod(lon)),start, stop);
        	cleaners.push_back(cl);
        	in_clean.get(c);
        	if (in_clean.eof()) {
        		break;
        	}
        	in_clean.seekg(-1, ios_base::cur);
        }
        in_clean.close();
    }
}

void Service::readUsers(string& csv_users, string& csv_providers) {
    ifstream in_user;
    string buffer;
    char c;
    in_user.open(csv_users);
    if( ! in_user.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_users << ">" << endl;
    } else {
        while (!in_user.eof()) {
        	string id;
        	string sensor_id;
        	getline(in_user, id, ';');
        	getline(in_user, sensor_id, ';');
        	//Ignore everything until the end of the line
        	getline(in_user, buffer, '\n');
        	list<Sensor*>::iterator it;
        	Individual* indiv = new Individual(id, id, id);
        	users.push_back(indiv);
        	for(it=sensors.begin();it!=sensors.end();it++){
			if ((*it)->getID()==sensor_id) {
				(*it)->setIndividual(indiv); 
				indiv->AddSensor((**it));
				break;
			}
		}
        	in_user.get(c);
        	if (in_user.eof()) {
        		break;
        	}
        	in_user.seekg(-1, ios_base::cur);
        }
        in_user.close();
    }
    ifstream in_provider;
    in_provider.open(csv_providers);
    if( ! in_provider.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_providers << ">" << endl;
    } else {
        while (!in_provider.eof()) {
        	string id;
        	string cleaner_id;
        	getline(in_provider, id, ';');
        	getline(in_provider, cleaner_id, ';');
        	//Ignore everything until the end of the line
        	getline(in_provider, buffer, '\n');
        	Provider* prov = new Provider(id, id, id);
        	users.push_back(prov);
        	list<Cleaner*>::iterator it;
        	for(it=cleaners.begin();it!=cleaners.end();it++){
			if ((*it)->getID()==cleaner_id) {
				(*it)->setProvider(prov); 
				prov->AddCleaner((**it));
				break;
			}
		}
        	in_provider.get(c);
        	if (in_provider.eof()) {
        		break;
        	}
        	in_provider.seekg(-1, ios_base::cur);
        }
        in_provider.close();
    }
    
    // Pour l'agence
    string id_agency = "Agency";
    Agency* agent = new Agency(id_agency, id_agency);
    users.push_back(agent);
}
