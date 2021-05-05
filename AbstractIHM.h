/*************************************************************************
                           AbstractIHM  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AbstractIHM> (fichier AbstractIHM.h) ----------------
#if ! defined ( AbstractIHM_H )
#define AbstractIHM_H

//--------------------------------------------------- Interfaces utilisées
#include "User"
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AbstractIHM>
//
//
//------------------------------------------------------------------------

class AbstractIHM 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void menuConnexion() const;
    
    int recupererChoix() const;
    
    string recupererChaine() const;
    
    virtual void afficherMenu() const =0;


//------------------------------------------------- Surcharge d'opérateurs
    AbstractIHM & operator = ( const AbstractIHM & unAbstractIHM);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AbstractIHM ( const AbstractIHM & unAbstractIHM);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AbstractIHM ( User & unUser);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AbstractIHM ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	User utilisateurConnecte;

};

//-------------------------------- Autres définitions dépendantes de <AbstractIHM>

#endif // AbstractIHM_H

