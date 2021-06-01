/*************************************************************************
                           Individual  -  description
                             -------------------
 début                : $05/05/2021$
 copyright          : (C) $2021$ par $hanaa Al zahabi$
 e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Individual> (fichier Individual.h) ----------------
#if ! defined ( INDIVIDUAL_H )
#define INDIVIDUAL_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "model/objet/User.h"
#include "model/objet/Sensor.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Individual>
//
//
//------------------------------------------------------------------------

class Individual : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	bool isReliable ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    
//-------------------------------------------- Getters - Setters
    const list<Sensor> GetSensors()const ;

    void AddSensor(Sensor & s);
    
    int GetPoints () const ;
    
    void SetReliable (bool reliable);
    
    void incrementerPoints() ;
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Individual ( const string & name, const string & password, const string & id, const list <Sensor> & sensors, bool reliable, int points);
    // Mode d'emploi () :
    //
    // Contrat :
    //
    
     Individual ( const string & name, const string & password, const string & id);
    // Mode d'emploi () :
    //
    // Contrat :
    //


    virtual ~Individual ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string id;
    list<Sensor> sensors;
    bool reliable;
    int points;
};

//-------------------------------- Autres définitions dépendantes de <Individual>

#endif // INDIVIDUAL_H
