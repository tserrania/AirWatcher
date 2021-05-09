/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $05/05/2021$
    copyright            : (C) $2021$ par $hanaa Al zahabi$
    e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "model/objet/Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Getters - Setters
list<Cleaner> & Provider::GetCleaners () const
{
    return cleaners;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Provider :: Provider ( const string & name, const string & passeword, const string & id, const list <Cleaner> & cleaners ) : User {name, passeword}
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Provider>" << endl;
    #endif
    this->id = id;
    this->cleaners = cleaners;
} //----- Fin de Provider


Provider::~Provider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
