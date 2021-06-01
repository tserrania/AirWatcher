/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined ( DATE_H )
#define DATE_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//
//------------------------------------------------------------------------

class Date 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int getJour();
    // Mode d'emploi :

    int getMois();
    // Mode d'emploi :

    int getAnnee();
    // Mode d'emploi :

    int getSec();
    // Mode d'emploi :
    
    int getMin();
    // Mode d'emploi :

    int getHeure();
    // Mode d'emploi :


//------------------------------------------------- Surcharge d'opérateurs
    Date & operator = ( const Date & unDate );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator == ( const Date & unDate );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool operator<=(const Date & unDate);
    
    bool operator>=(const Date & unDate);

//-------------------------------------------- Constructeurs - destructeur
    Date ( const Date & unDate );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Date ( int a,int m,int j,int h,int mi,int s);
    // Mode d'emploi:
    //
    // Contrat :
    //

    //~ Date ( );
    //~ // Mode d'emploi :
    //~ //
    //~ // Contrat :
    //~ //
    
    Date (const string & stringDate);

    virtual ~Date ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    int heure;
    int min;
    int sec;
    int jour;
    int mois;
    int annee;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // Date_H

