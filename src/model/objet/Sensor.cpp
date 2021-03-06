/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "model/objet/Sensor.h"
#include "model/objet/Individual.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Sensor::setIndividual(Individual *indiv) {
	individual = indiv;
}

string Sensor::getID() const{
	return ID ;
}

Point Sensor::getLocation() const{
	return location ;
}

bool Sensor::isNear(const Point & center, double radius) const{
	return location.getDistance(center) <= radius ;
}

string Sensor::isValid() const{
	return valid ;
}

void Sensor::setValid(string valide) {
    valid = valide ;
}

const list<Measurement> & Sensor::getMesures() const{
    
	return mesures ;
}

double Sensor::getValue(const Date & debut, const Date & fin, const Attribute & attribute) const{
	double somme = 0 ;
	int cpt = 0 ;
	list<Measurement> :: const_iterator it ;
	for ( it = mesures.begin(); it != mesures.end(); it++ )
	{
		if(it->getDate() >= debut && it->getDate() <= fin && it->getAttribute() == attribute){
			somme += it->getValue() ;
			cpt++ ;
		}
	}
	if(cpt == 0){ //pas de mesures pour cette intervalle
		return -1 ;
	}
	return somme/cpt;
}

double Sensor::getLastValue(const string attribut) const{
    double value = -1 ;
    Date date = mesures.begin()->getDate() ;
    list<Measurement> :: const_iterator it ;
    for ( it = mesures.begin(); it != mesures.end(); it++ )
    {
        if(it->getDate() >= date && it->getAttribute().getID() == attribut){
            date = it->getDate() ;
            value = it->getValue() ;
        }
    }
    return value ;
}

void Sensor::incrementerPointsUtilisateur(){
    if(individual != nullptr) {
        individual->incrementerPoints() ;
    }
}



//------------------------------------------------- Surcharge d'opérateurs
Sensor & Sensor::operator = ( const Sensor & unSensor )
// Algorithme :
//
{
	if(this!=&unSensor){
		delete individual;
		this->individual= new Individual(*(unSensor.individual));
		this->ID = unSensor.ID ;
		this->location = unSensor.location ;
		this->mesures = unSensor.mesures ;
	}

	return *this ;
} //----- Fin de operator =

bool Sensor::operator == ( const Sensor & unSensor )
// Algorithme :
//
{
	if(ID == unSensor.ID){
		return true ;
	}
	return false ;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor ):ID(unSensor.ID),location(unSensor.location), valid(unSensor.valid),
mesures(unSensor.mesures)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
	this->individual = unSensor.individual;
} //----- Fin de Sensor (constructeur de copie)

Sensor::Sensor ( const string & unID, const Point & Location, const string & Valid, const list<Measurement> & Mesures, Individual *unIndiv )
:ID(unID),location(Location),valid(Valid), mesures(Mesures)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
	this->individual = unIndiv;
} //----- Fin de Sensor (constructeur de copie)


Sensor::~Sensor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

