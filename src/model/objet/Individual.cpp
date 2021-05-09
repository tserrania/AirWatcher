/*************************************************************************
 Individual  -  description
                             -------------------
    début                : $05/05/2021$
    copyright            : (C) $2021$ par $hanaa Al zahabi$
    e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Individual> (fichier Individual.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <stdio.h>
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
    list <Sensor> :: iterator it ;
    for ( it= sensors.begin(); it != sensors.end(); it++ )
    {
        if( !( it -> isValid() ) ) reliable= false;
    }
    return reliable; 
}

//-------------------------------------------- Getters - Setters
list<Sensor> Individual :: GetSensors()const
{
    return sensors; 
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
Individual :: Individual ( const string & name, const string & password, const string & id, const list <Sensor> & sensors, bool reliable, int points): User {name, passeword}
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Individual>" << endl;
    #endif
    this->id=id;
    this->sensors = sensors;
    this->reliable= reliable;
    this->points = points;
    
} //----- Fin de Individual


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

