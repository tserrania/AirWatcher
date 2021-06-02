/*************************************************************************
 Individual  -  description
                             -------------------
    début                : $05/05/2021$
    copyright            : (C) $2021$ par $hanaa Al zahabi$
    e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Individual> (fichier Individual.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systèmes
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "model/objet/Individual.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Individual :: isReliable ( ) const
{
    bool reliable = true;
    list <Sensor> :: const_iterator it ;
    for ( it= sensors.cbegin(); it != sensors.end(); it++ )
    {
        if(it->isValid()!="valide"){
			 reliable= false;
		 }
    }
    return reliable; 
}

//-------------------------------------------- Getters - Setters
const list<Sensor> Individual :: GetSensors()const
{
    return sensors; 
}

void Individual :: AddSensor(Sensor & s)
{
    sensors.push_back(s); 
}

int Individual :: GetPoints () const
{
    return points;
}

void Individual :: SetReliable (bool reliable)
{
    this->reliable = reliable;
}

void Individual :: incrementerPoints(){
	points++ ;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Individual :: Individual ( const string & name, const string & password, const string & ID, const list <Sensor> & Sensors, bool reliable, int points): 
User (name, password), id(ID), sensors(Sensors)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Individual>" << endl;
    #endif
    this->reliable= reliable;
    this->points = points;
    
} //----- Fin de Individual

Individual::Individual(const string & name, const string & password, const string & ID):User(name,password), id(ID){
	#ifdef MAP
        cout << "Appel au constructeur de <Individual>" << endl;
    #endif
    reliable=true;
    points=0;
}


Individual::~Individual ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Individual>" << endl;
#endif
} //----- Fin de ~Individual


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

