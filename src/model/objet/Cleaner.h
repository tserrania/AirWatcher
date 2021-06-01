/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined ( CLEANER_H )
#define CLEANER_H
#include <string>
#include <list>
#include "model/objet/Point.h"
#include "model/objet/Sensor.h"
#include "model/objet/Date.h"
#include "model/objet/Provider.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Provider;

class Cleaner 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    Provider* getProvider();
    // Mode d'emploi :
    // Recupère le Provider du Cleaner
    
    void setProvider(Provider* p);
    // Mode d'emploi :
    // Définit le Provider du Cleaner
    
    const string& getID();
    // Mode d'emploi :
    // Recupère l'ID du Cleaner

    const Point& getLocation();
    // Mode d'emploi :
    // Recupère l'emplacement du Cleaner

    const Date& getStart();
    // Mode d'emploi :
    // Recupère la date de mise en service du Cleaner

    const Date& getStop();
    // Mode d'emploi :
    // Recupère la date d'arrêt du Cleaner


//------------------------------------------------- Surcharge d'opérateurs

	Cleaner & operator =(const Cleaner & unCleaner);


//-------------------------------------------- Constructeurs - destructeur
    Cleaner ( const Cleaner & unCleaner );
    // Mode d'emploi (constructeur de copie) :
    // Construit une copie d'un cleaner identique à un autre

    Cleaner ( string Id,Provider *provider,Point location,Date start,Date stop );
    // Mode d'emploi :
    // Construit un cleaner avec ses attributs

    virtual ~Cleaner ( );
    // Mode d'emploi :
    // Détruit le cleaner

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    string id;
    Provider *provider;
    Point location;
    Date start;
    Date stop;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // Cleaner_H

