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
#include "Agency.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Getters - Setters

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Agency :: Agency ( const string & name, const string & passeword ) : User {name, passeword}
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

