/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "model/objet/Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Measurement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Measurement & Measurement::operator = ( const Measurement & unMeasurement )
// Algorithme :
//
{
	if(this!=&unMeasurement){
		timeStamp=unMeasurement.timeStamp;
		attribut=unMeasurement.attribut;
		value=unMeasurement.value;
	}

	return *this ;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement ( const Measurement & m ):timeStamp(m.timeStamp), attribut(m.attribut), value(m.value)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement (const Date date, const Attribute & unAttribut, double v):timeStamp(date),attribut(unAttribut), value(v)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- Fin de Measurement


Measurement::~Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

