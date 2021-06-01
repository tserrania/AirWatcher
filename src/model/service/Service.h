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
#include <string>
#include "model/objet/Cleaner.h"
#include "model/objet/Date.h"
#include "model/objet/User.h"
#include "model/objet/Sensor.h"

using namespace std;

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
    
    string checkSensor (string idSensor) ;
    
    void afficheVerification() ;
    
    
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void MesurerPerformancePurificateur (string & cleaner_id) ;
    
    Sensor * getSensorByID(const string & sensorID);
    
    User * authentifier(const string & id, const string & mdp);


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
    
    void afficheSensors() ;

    void afficheMeasurements() ;

    Date readDate(ifstream& ifs) ;
    
    Cleaner* findCleaner(const string & cleaner_id);
    void sortByDistance(const Point & location);
    void calculerPourcentageAttributs(map<Attribute, double> & ecart_courant, const Sensor & s, const Date & start, const Date & stop);
    bool estEfficace(const map<Attribute, double> & ecart_courant, double seuil);

    void readSensors(string& csv_attributes, string& csv_measurements, string& csv_sensors) ;
    void readUsers(string& csv_users, string& csv_providers) ;
    void readCleaners(string& csv_cleaners) ;

//----------------------------------------------------- Attributs protégés
    list<User*> users;
    list<Sensor*> sensors;
    list<Cleaner*> cleaners;
};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // SERVICE_H

