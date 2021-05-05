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
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool User :: isEqual ( string name, string passeword)
{
    return ( this.name==name && this.passeword==passeword);
}

//-------------------------------------------- Getters - Setters
string User :: GetName () const
{
    return name;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
User :: User ( const string & name, const string & passeword );
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <User>" << endl;
    #endif
    
    this.name = name;
    this.passeword = passeword;
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
