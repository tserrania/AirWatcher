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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Service :: StartProcedure () {
    checkSensors() ;
}

void Service :: MesurerPerformancePurificateur (string & cleaner_id) {
    Cleaner* cl = findCleaner(cleaner_id);
    sortByDistance(cl->getLocation());
    map<Attribute, pair<double, int>> total_ecarts;
    double distance_max = 0.0f;
    double seuil = 0.1f;
    
    list<Sensor*>::iterator currentSensor;
    for(currentSensor=sensors.begin(); currentSensor!=sensors.end(); currentSensor++)
    {
    	map<Attribute, double> ecart_courant;
    	calculerPourcentageAttributs(ecart_courant, **currentSensor, cl->getStart(), cl->getStop());
    	if (estEfficace(ecart_courant, seuil)) {
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
		distance_max = (*currentSensor) -> getLocation().getDistance(cl->getLocation());
    	} else {
    		break;
    	}
    }
    map<Attribute, double> moyenne_ecarts;
    map<Attribute,pair<double, int>>::iterator it;
    for(it=total_ecarts.begin(); it!=total_ecarts.end(); it++)
    {
    	Attribute a = it->first;
	double total = it->second.first;
	int nombre = it->second.second;
	moyenne_ecarts.insert(make_pair(a, total/nombre));
    }
    cout << distance_max;
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

void Service :: checkSensors () {

    list<Sensor*>::iterator currentSensor;
    list<Sensor*>::iterator comparedSensor;
    
    
    int const tailleTab (4) ;
    double distanceSeuil = 20 ;
    double moyenne [tailleTab] = { 0, 0, 0, 0 };
    double seuilsProximite [tailleTab] = { 5, 5, 5, 2 };
    double seuilsDerivees [tailleTab] = { 5, 5, 5, 2 };

    for(currentSensor=sensors.begin(); currentSensor!=sensors.end(); currentSensor++)
    {
        
        int nbSensorsProches = 0 ;
        Point currentLocation = (*currentSensor)->getLocation();
        for(comparedSensor=sensors.begin(); comparedSensor!=sensors.end(); comparedSensor++)
        {
            double distance = (*comparedSensor)->getLocation().getDistance(currentLocation);
            if(distance > 0 && distance <= distanceSeuil){
                if((*comparedSensor)->getLastValue("O3") == -1 || (*comparedSensor)->getLastValue("NO2") == -1 || (*comparedSensor)->getLastValue("SO2") == -1 || (*comparedSensor)->getLastValue("PM10") == -1 ){
                    cerr << "Problème dans la methode checkSensors dans la partie proximité : attribut inexistant" << endl ;
                    break ;
                }
                moyenne[0] += (*comparedSensor)->getLastValue("O3") ;
                moyenne[1] += (*comparedSensor)->getLastValue("NO2") ;
                moyenne[2] += (*comparedSensor)->getLastValue("SO2") ;
                moyenne[3] += (*comparedSensor)->getLastValue("PM10") ;
                nbSensorsProches ++ ;
            }
        }
        
        bool validiteProximite = true ;
        
        string titres [tailleTab] = {"O3", "NO2", "SO2", "PM10"} ;
        
        for(int i = 0 ; i < tailleTab ; i++ ){
            if(nbSensorsProches != 0){
                moyenne[i] /= nbSensorsProches ;
                if(abs(moyenne[i] - (*currentSensor) -> getLastValue(titres[i])) > distanceSeuil){
                    validiteProximite = false ;
                    break ;
                }
            }
        }
        
        
        
        double precedentValues [tailleTab] ;
        double currentValues [tailleTab] ;
        double maxDifferences [tailleTab] ;
        
        for(int i(0); i<tailleTab; i++)
        {
            precedentValues[i] = -1 ;
            maxDifferences[i] = 0 ;
        }
        
        list<Measurement>::const_iterator currentMeasurement ;
        bool mesuresValides = true ;
        
        for(currentMeasurement=(*currentSensor)->getMesures().begin() ; currentMeasurement!=(*currentSensor)->getMesures().end() ; currentMeasurement++)
        {
            int typeMesure (-1) ; //0 pour O3, 1 pour NO2, 2 pour SO2 et 3 pour PM10
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
            
            if(typeMesure == -1){
                mesuresValides = false ;
                break ;
            }
            
            if(precedentValues[typeMesure] == -1){ //tableau pas encore initialisé pour cette valeur
                precedentValues[typeMesure] = currentMeasurement->getValue() ;
            } else { //tableau initialisé donc on peut comparer
                currentValues[typeMesure] = currentMeasurement->getValue() ;
                double difference = currentValues[typeMesure]-precedentValues[typeMesure] ;
                maxDifferences[typeMesure] = max(maxDifferences[typeMesure], abs(difference)) ;
            }
        }
        
        bool validiteDerivee = true ;
        
        if(!mesuresValides){
            validiteDerivee = false ;
        } else {
            for(int i(0); i<tailleTab; i++){
                if(maxDifferences[i] > seuilsDerivees[i]){ //la derivee est toujours positive donc pas besoin de verifier la valeur absolue
                    validiteDerivee = false ;
                    break ;
                }
            }
        }
        
        if(validiteProximite && validiteDerivee){
            (*currentSensor)->setValid("valide") ;
        } else if(!validiteProximite && !validiteDerivee){
            (*currentSensor)->setValid("defectueux") ;
        } else {
            (*currentSensor)->setValid("incertain") ;
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
		return dist_a - dist_b;
	});
	
}

void Service::calculerPourcentageAttributs(map<Attribute, double> & ecart_courant, const Sensor & s, const Date & start, const Date & stop) {
	
}

bool Service::estEfficace(const map<Attribute, double> & ecart_courant, double seuil) {
	return false;
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
        	//cout << "new --> " << endl;
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
        	
        	//list<Measurement> ms(measurements.lower_bound(sensor_id), measurements.upper_bound(sensor_id));
        	list<Measurement> ms;
        	multimap<string,Measurement>::const_iterator it;
        	for(it=measurements.lower_bound(sensor_id);it!=measurements.upper_bound(sensor_id);it++){
			ms.push_back(it->second);
		}
		Sensor* s = new Sensor(sensor_id, Point(stod(lat), stod(lon)),"valid", ms);
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
        	Individual* indiv = new Individual("", "", id);
        	users.push_back(indiv);
        	cout << id << endl;
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
        	Provider* prov = new Provider("", "", id);
        	users.push_back(prov);
        	cout << id << endl;
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
}
