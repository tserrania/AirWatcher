/*************************************************************************
                           User  -  description
                             -------------------
    début                : $05/05/2021$
    copyright            : (C) $2021$ par $hanaa Al zahabi$
    e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <stdio.h>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "model/objet/User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool User :: isEqual ( string name, string passeword)
{
    return ( this->name==name && this->passeword==passeword);
}

//-------------------------------------------- Getters - Setters
const string & User :: GetName () const
{
    return name;
}

//------------------------------------------------- Surcharge d'opérateurs

User & User::operator =(const User & unUser){
	if(this!=&unUser){
		name=unUser.name;
		passeword=unUser.passeword;
	}
	return(*this);
}

//-------------------------------------------- Constructeurs - destructeur

User::User(const User & unUser):name(unUser.name),passeword(unUser.passeword)
{
	#ifdef MAP
        cout << "Appel au constructeur de copie de <User>" << endl;
    #endif
}
User :: User ( const string & Name, const string & Passeword ):name(Name), passeword(Passeword)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <User>" << endl;
    #endif
} //----- Fin de User


User::~User ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
