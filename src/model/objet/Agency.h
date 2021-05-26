/*************************************************************************
                           Agency  -  description
                             -------------------
 début                : $05/05/2021$
 copyright          : (C) $2021$ par $hanaa Al zahabi$
 e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Agency> (fichier Agency.h) ----------------
#if ! defined ( AGENCY_H )
#define AGENCY_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include "model/objet/User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Agency>
//
//
//------------------------------------------------------------------------

class Agency : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Getters - Setters
      
//------------------------------------------------- Surcharge d'opérateurs

	Agency & operator=(const Agency & unAgency);


//-------------------------------------------- Constructeurs - destructeur
	Agency (const Agency & unAgency);
    Agency ( const string & name, const string & password );
    // Mode d'emploi () :
    //
    // Contrat :
    //


    virtual ~Agency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Agency>

#endif // AGENCY_H

