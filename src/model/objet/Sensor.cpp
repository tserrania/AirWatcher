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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Sensor::setIndividual(const Individual & indiv) {
	individual = indiv ;
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

list<Measurement> & Sensor::getMesures() const{
	return mesures ;
}

double Sensor::getValue(const Date & debut, const Date & fin, const Attribute & attribute) const{
	double somme = 0 ;
	int cpt = 0 ;
	list<Measurement> :: iterator it ;
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

void Sensor::incrementerPointsUtilisateur(){
	individual.incrementerPoints() ;
}



//------------------------------------------------- Surcharge d'opérateurs
Sensor & Sensor::operator = ( const Sensor & unSensor )
// Algorithme :
//
{
	this->ID = unSensor.ID ;
	this->location = unSensor.location ;
	this->mesures = unSensor.mesures ;

	return this ;
} //----- Fin de operator =

bool Sensor::operator == ( const Sensor & unSensor )
// Algorithme :
//
{
	if(ID == unSensor.ID && location == unSensor.location && mesures == unSensor.mesures){
		return true ;
	}
	return false ;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
    this->ID = unSensor.ID ;
    this->location = unSensor.location ;
    this->mesures = unSensor.mesures ;
} //----- Fin de Sensor (constructeur de copie)

Sensor::Sensor ( const string ID, const Point & location, const list<Measurement> & mesures )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
    this->ID = ID ;
    this->location = location ;
    this->mesures = mesures ;
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

