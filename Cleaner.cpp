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
#include "Cleaner.h"
#include <string>
#include "Point.h"
#include "Provider.h"
#include "Sensor.h"
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Cleaner::getId()
{
    return id;
}

Point Cleaner::getLocation()
{
    return location;
}

Date Cleaner::getStart();
{
    return start;
}

Date Cleaner::getStop()
{
    return stop;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
    id = unCleaner.id;
    provider = unCleaner.provider;
    location = unCleaner.location;
    start = unCleaner.start;
    stop = unCleaner.stop;
} //----- Fin de Cleaner (constructeur de copie)

Cleaner::Cleaner (string ID, Provider pr,Point po,Date st,Date sp )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
    id = ID;
    provider = pr;
    location = po;
    start = st;
    stop = sp;
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

