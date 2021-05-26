/*************************************************************************
                           IHMAgency  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <IHMAgency> (fichier IHMAgency.h) ----------------
#if ! defined ( IHMAgency_H )
#define IHMAgency_H

//--------------------------------------------------- Interfaces utilisées
#include "view/AbstractIHM.h"
#include "model/objet/User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IHMAgency>
//
//
//------------------------------------------------------------------------

class IHMAgency : public AbstractIHM
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void afficherMenu() const;
    
    void selectionCapteurDefectueux() const;
    
    void afficherCapteurDefectueux(const string & etatCapteur) const;


//------------------------------------------------- Surcharge d'opérateurs
    IHMAgency & operator = ( const IHMAgency & unIHMAgency);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    IHMAgency ( const IHMAgency & unIHMAgency);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    IHMAgency (User & unUser);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~IHMAgency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <IHMAgency>

#endif // IHMAgency_H

