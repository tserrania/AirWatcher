/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "model/objet/Point.h"

//------------------------------------------------------------- Constantes
const double earth_radius = 6371.0;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
double Point::getLatitude() { return latitude; }

double Point::getLongitude() { return longitude; }

double Point::getDistance(const Point& unPoint) const
// Algorithme : 
// Calcul de la distance avec la formule de Haversine
{
    double a = pow(sin((latitude-unPoint.latitude)/2),2)+cos(latitude)*cos(unPoint.latitude)*pow(sin((longitude-unPoint.longitude)/2),2);
    double c = 2*atan2(sqrt(a), sqrt(1-a));
    return earth_radius*c;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
    latitude = unPoint.latitude;
    longitude = unPoint.longitude;
} //----- Fin de Point (constructeur de copie)


Point::Point (double lat, double lon)
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
    latitude = lat;
    longitude = lon;
} //----- Fin de Point


Point::~Point ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

