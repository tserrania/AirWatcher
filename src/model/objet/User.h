/*************************************************************************
                           User  -  description
                             -------------------
 début                : $05/05/2021$
 copyright          : (C) $2021$ par $hanaa Al zahabi$
 e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool isEqual ( string name, string passeword);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
//-------------------------------------------- Getters - Setters
    string GetName()const ;
      
//------------------------------------------------- Surcharge d'opérateurs

	User & operator =(const User & unUser);

//-------------------------------------------- Constructeurs - destructeur

	User (const User & unUser);
    User ( const string & name, const string & passeword );
    // Mode d'emploi () :
    //
    // Contrat :
    //


    virtual ~User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string name;
    string passeword;
};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // USER_H

