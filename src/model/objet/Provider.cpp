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
void Provider::AddCleaner (Cleaner & c)
{
    cleaners.push_back(c);
}

const list<Cleaner> & Provider::GetCleaners () const
{
    return cleaners;
}

//------------------------------------------------- Surcharge d'opérateurs

Provider & Provider::operator =(const Provider & unProvider){
	if(this!=&unProvider){
		name=unProvider.name;
		passeword=unProvider.passeword;
		id=unProvider.id;
		cleaners=unProvider.cleaners;
	}
	return(*this);
}

//-------------------------------------------- Constructeurs - destructeur
Provider :: Provider ( const string & name, const string & passeword, const string & ID, const list <Cleaner> & Cleaners ) : User (name, passeword),
id(ID), cleaners(Cleaners)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Provider>" << endl;
    #endif
} //----- Fin de Provider

Provider :: Provider ( const string & name, const string & passeword, const string & ID ) : User (name, passeword),
id(ID)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Provider>" << endl;
    #endif
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
