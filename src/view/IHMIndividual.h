/*************************************************************************
                           IHMIndividual  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <IHMIndividual> (fichier IHMIndividual.h) ----------------
#if ! defined ( IHMIndividual_H )
#define IHMIndividual_H

//--------------------------------------------------- Interfaces utilisées

#include "AbstractIHM.h"
#include "Attribute.h"
#include "model/objet/User.h"
#include <map>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IHMIndividual>
//
//
//------------------------------------------------------------------------

class IHMIndividual : public AbstractIHM
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
    
    void afficherPoints(int points) const;


//------------------------------------------------- Surcharge d'opérateurs
    IHMIndividual & operator = ( const IHMIndividual & unIHMIndividual);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    IHMIndividual ( const IHMIndividual & unIHMIndividual);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    IHMIndividual (User & unUser);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~IHMIndividual ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <IHMIndividual>

#endif // IHMIndividual_H

