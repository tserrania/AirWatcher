/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#if ! defined ( Attribute_H )
#define Attribute_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribute>
//
//
//------------------------------------------------------------------------

class Attribute 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    const string & getID() const{return ID;}
    
    const string & getUnit() const{return unit;}
    
    const string & getDescription() const{return description;}


//------------------------------------------------- Surcharge d'opérateurs
    Attribute & operator = ( const Attribute & unAttribute);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool operator ==(const Attribute & unAttribute) const {return ID==unAttribute.ID;}
    
    bool operator <(const Attribute & unAttribute) const {return ID<unAttribute.ID;}
    
    friend ostream & operator<<(ostream & os, const Attribute & unAttribute);


//-------------------------------------------- Constructeurs - destructeur
    Attribute ( const Attribute & unAttribute);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Attribute (string identifiant);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attribute ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string ID;
	string unit;
	string description;

};

//-------------------------------- Autres définitions dépendantes de <Attribute>

#endif // Attribute_H

