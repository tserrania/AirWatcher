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

#include <iostream>
using namespace std;
#include <string>
#include "Point.h"
#include "Measurement.h"
#include "Individual.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

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

    int getID() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int getLocation() const;
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

    List<Measurement> & getMesures() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    double getValue(const date & debut, const date & fin, const Attribute & attribute) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    double * getValues(const date & debut, const date & fin) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

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


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor ( );
    // Mode d'emploi :
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
	Individual individual ;

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H

