/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées

#include <list>
#include <string>
#include "model/objet/Date.h"
#include "model/objet/Point.h"
#include "model/objet/Measurement.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Individual;

class Sensor 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setIndividual(const Individual *indiv) ;
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getID() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point getLocation() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool isNear(const Point & center, double radius) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    string isValid() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setValid(string valide);
    // Mode d'emploi :
    //
    // Contrat :
    //

    const list<Measurement> & getMesures() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    double getValue(const Date & debut, const Date & fin, const Attribute & attribute) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    double getLastValue(const string attribut) const ;

    void incrementerPointsUtilisateur() ;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator == ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    Sensor ( const string & ID, const Point & location, const string & Valid, const list<Measurement> & mesures, const Individual *unIndiv=nullptr);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	string ID ;
	Point location ;
	string valid ;
	list<Measurement> mesures ;
	Individual *individual ;

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H

