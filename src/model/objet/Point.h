/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ----------------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------

class Point 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    double getLatitude();
    // Mode d'emploi :
    //	Retourne la latitude de ce point
    
    double getLongitude();
    // Mode d'emploi :
    //	Retourne la longitude de ce point
    
    double getDistance(const Point& unPoint) const;
    // Mode d'emploi :
    //	Calcule la distance avec un autre point

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    // Construit un point à partir d'un autre
    
    Point (double lat, double lon);
    // Mode d'emploi :
    // Construit un point avec sa latitude et sa longitude

    virtual ~Point ( );
    // Mode d'emploi :
    // Détruit le point

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    double latitude;
    double longitude;
};

//-------------------------------- Autres définitions dépendantes de <Point>

#endif // POINT_H

