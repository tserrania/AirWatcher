/*************************************************************************
                           Provider  -  description
                             -------------------
 début                : $05/05/2021$
 copyright          : (C) $2021$ par $hanaa Al zahabi$
 e-mail               : $hanaa.al-zahabi@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//------------------------------------------------------------------------

class Provider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Getters - Setters
    public list <Cleaner> GetCleaners () const; 
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Provider ( const string & name, const string & passeword, const string & id, const list <Cleaner> & cleaners );
    // Mode d'emploi () :
    //
    // Contrat :
    //


    virtual ~Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string id;
    list <Cleaner> cleaners;
};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H
