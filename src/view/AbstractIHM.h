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
#include "model/objet/User.h"
#include "model/objet/Attribute.h"
#include <string>
#include <map>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AbstractIHM>
//Classe abstrait qui permet de gérer les différentes interfaces disponibles pour chaque utilisateur (membre de l'agence, industriel, ou particulier)
//On regroupe ici plusieurs méthodes abstraites communes à chaque IHM, dont le choix se fait en fonction de l'utilisateur connecté,
//qui est un attribut de la classe
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
    
    void accueil() const;
    
    void menuConnexion(string & id, string & mdp) const;
    //Affichage console pour demander à l'utilisateur son identifiant et son mot de passe et ainsi se connecter
     
    
    int recupererChoix() const;
    //Permet de récupérer un input utilisateur sous forme d'entier. Si l'entrée clavier n'est pas un chiffre entre 0 et 9, la méthode
    //renvoie -1
    
    string recupererChaine() const;
    //Permet de récupérer un input utlilisateur sous forme de chaîne de caractères
    
    virtual int traduireChoix(int choix) const=0;
    //Méthode virtuelle pure qui permet, en fonction du choix de l'utilisateur, de renvoyer un nombre qui indiquera au contrôleur
    //quel service invoquer. Par exemple, pour 2 utilisateurs différents, il faudra appuyer sur la même touche pour lancer deux services
    //différents, selon l'IHM. Cette méthode permet donc de réaliser cette traduction
    
    virtual void afficherMenu() const =0;
    //Affiche les différentes fonctionnalités auxquelles a accès l'utilisateur ainsi que le numéro à écrire pour la lancer
    
    virtual void afficherPoints(int points) const{}
    
    virtual void afficherEfficacite(const map<Attribute,double> & pourcentages, double rayonAction) const{}
    
    virtual void afficherCapteurDefectueux(const string & etatCapteur) const{}
    
    


//------------------------------------------------- Surcharge d'opérateurs
    AbstractIHM & operator = ( const AbstractIHM & unAbstractIHM);
    // Opérateur d'affectation


//-------------------------------------------- Constructeurs - destructeur
    AbstractIHM ( const AbstractIHM & unAbstractIHM);
    // Constructeur de copie:
    

    AbstractIHM ( const User & unUser);
    // Constructeur avec l'attribut utilisateurConnecté fourni en paramètre. Il peut s'agir d'un objet Agency, Provider, ou Individual

    virtual ~AbstractIHM ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	User utilisateurConnecte; //Indique quel type d'utilisateur est connecté, et donc quel IHM utiliser

};

//-------------------------------- Autres définitions dépendantes de <AbstractIHM>

#endif // AbstractIHM_H

