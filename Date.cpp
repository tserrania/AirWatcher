/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Date::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int Date::getSec(){
 return sec;
}
int Date::getMin(){
 return min;
}
int Date::getHeure(){
 return heure;
}
int Date::getJour(){
 return jour;
}
int Date::getMois(){
 return mois;
}
int Date::getAnnee(){
 return annee;
}


//------------------------------------------------- Surcharge d'opérateurs
bool Date::operator == ( const Date & unDate )
// Algorithme :
//
{
	if(this.heure == unDate.heure && this.min == unDate.min && this.sec == unDate.sec && this.jour == unDate.jour && this.mois == unDate.mois && this.annee == unDate.annee )
	{
		return true;
	}

	return false;
} //----- Fin de operator ==


//-------------------------------------------- Constructeurs - destructeur
Date::Date ( const Date & unDate )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
    sec = unDate.sec;
    min = unDate.min;
    heure = unDate.heure;
    jour = unDate.jour;
    mois = unDate.mois;
    annee = unDate.annee;
} //----- Fin de Date (constructeur de copie)

//-------------------------------------------- Constructeurs - destructeur
Date::Date ( int a,int m,int j,int h,int mi,int s )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
    sec = s;
    min = mi;
    heure = h;
    jour = j;
    mois = m;
    annee = a;
} //----- Fin de Date (constructeur de copie)


Date::Date ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Date>" << endl;
#endif
} //----- Fin de Date


Date::~Date ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Date>" << endl;
#endif
} //----- Fin de ~Date


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

