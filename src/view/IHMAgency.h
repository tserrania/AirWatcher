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
// Rôle de la classe <IHMAgency>, hérite de AbstractIHM
//IHM propre aux membres de l'agence gouvernementale. Ils n'ont accès qu'aux fonctionnalités pour détecter un capteur défectueux
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
    //Permet à l'utilisateur de taper au clavier l'identifiant du capteur qu'il souhaite analyser
    
    void afficherCapteurDefectueux(const string & etatCapteur) const;
    //Une fois les traitements réalisés, on affiche l'état du capteur, soit fonctionnel, soit défectueux, soit incertain, soit non trouvé
    
    int traduireChoix(int choix) const;


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
