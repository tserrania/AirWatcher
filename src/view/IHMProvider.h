/*************************************************************************
                           IHMProvider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <IHMProvider> (fichier IHMProvider.h) ----------------
#if ! defined ( IHMProvider_H )
#define IHMProvider_H

//--------------------------------------------------- Interfaces utilisées

#include "AbstractIHM.h"
#include "model/objet/Attribute.h"
#include "model/objet/User.h"
#include <map>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IHMProvider>
//
//
//------------------------------------------------------------------------

class IHMProvider : public AbstractIHM
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
    
    void selectionCleaner() const;
    
    void afficherEfficacite(const map<Attribute,double> & pourcentages, double rayonAction) const;


//------------------------------------------------- Surcharge d'opérateurs
    IHMProvider & operator = ( const IHMProvider & unIHMProvider);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    IHMProvider ( const IHMProvider & unIHMProvider);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    IHMProvider (User & unUser);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~IHMProvider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <IHMProvider>

#endif // IHMProvider_H

