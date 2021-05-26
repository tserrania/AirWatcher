/*************************************************************************
                           Agency  -  description
                             -------------------
    début                : $05/05/2021$
    copyright            : (C) $2021$ par $hanaa Al zahabi$
    e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Agency> (fichier Agency.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include <stdio.h>
#include <iostream>
using namespace std;
#include "model/objet/Agency.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Getters - Setters

//------------------------------------------------- Surcharge d'opérateurs

Agency & Agency::operator =(const Agency & unAgency){
	if(this!=&unAgency){
		name=unAgency.name;
		passeword=unAgency.passeword;
	}
	return(*this);
}

//-------------------------------------------- Constructeurs - destructeur

Agency::Agency(const Agency & unAgency):User(unAgency.name,unAgency.passeword)
{
	#ifdef MAP
        cout << "Appel au constructeur de copie de <Agency>" << endl;
    #endif
}
Agency :: Agency ( const string & name, const string & password ) : User (name, passeword)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Agency>" << endl;
    #endif
} //----- Fin de Agency


Agency::~Agency ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Agency>" << endl;
#endif
} //----- Fin de ~Agency


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

