/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Interface de la classe <Service> (fichier Service.h) ----------------
#if ! defined ( SERVICE_H )
#define SERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <list>

#include "model/objet/Cleaner.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
//
//------------------------------------------------------------------------

class Service 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Service ( const Service & unService );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Service (string csv_attributes, string csv_cleaners, string csv_measurements, string csv_providers, string csv_sensors, string csv_users) ;
    // Mode d'emploi :
    // 

    virtual ~Service ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    Date readDate(ifstream& ifs) ;

    void readSensors(string& csv_attributes, string& csv_measurements, string& csv_sensors) ;

//----------------------------------------------------- Attributs protégés
    list<User> users;
    list<Sensor> sensors;
    list<Cleaner> cleaners;
};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // SERVICE_H

