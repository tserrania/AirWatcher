/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "model/objet/Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Provider* Cleaner::getProvider()
{
    return provider;
}

void Cleaner::setProvider(Provider* p)
{
    provider = p;
}

const string& Cleaner::getID()
{
    return id;
}

const Point& Cleaner::getLocation()
{
    return location;
}

const Date& Cleaner::getStart()
{
    return start;
}

const Date& Cleaner::getStop()
{
    return stop;
}

//------------------------------------------------- Surcharge d'opérateurs

Cleaner & Cleaner::operator =(const Cleaner & unCleaner){
	if(this!=&unCleaner){
		id=unCleaner.id;
		provider=unCleaner.provider;
		location=unCleaner.location;
		start=unCleaner.start;
		stop=unCleaner.stop;
	}
	return(*this);
}

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner ):id(unCleaner.id),provider(unCleaner.provider),location(unCleaner.location),
start(unCleaner.start),stop(unCleaner.stop)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner (constructeur de copie)

Cleaner::Cleaner (string ID, Provider *pr,Point po,Date st,Date sp ):id(ID),provider(pr),location(po),start(st),stop(sp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner


Cleaner::~Cleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

