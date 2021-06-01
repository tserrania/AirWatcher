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

#include "view/AbstractIHM.h"
#include "model/objet/Attribute.h"
#include "model/objet/User.h"
#include <map>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IHMProvider>
//IHM propre aux fournisseus de purificateurs d'air. Ceux-ci n'ont accès qu'à la mesure de l'efficacité des purificateurs
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
    //Permet à l'utilisateur de rentrer au clavier l'identifiant du purificateur à analyser
    
    
    void afficherEfficacite(const map<Attribute,double> & pourcentages, double rayonAction) const;
    //Une fois les calculs effectués, on affiche les résultats en indiquant pour chaque Attribut, c'est à dire chaque type de polluant,
    //quel est le pourcentage d'efficacité du purificateur avant et après son fonctionnement, ainsi que son rayon d'action
    
    int traduireChoix(int choix) const;


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

