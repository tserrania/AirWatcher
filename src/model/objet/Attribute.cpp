/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "model/objet/Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Attribute::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Attribute & Attribute::operator = ( const Attribute & unAttribute )
// Algorithme :
//
{
	if(this!=&unAttribute){
		ID=unAttribute.ID;
		unit=unAttribute.unit;
		description=unAttribute.description;
	}
	return(*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Attribute::Attribute ( const Attribute & unAttribute ):ID(unAttribute.ID), unit(unAttribute.unit), description(unAttribute.description)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribute>" << endl;
#endif
} //----- Fin de Attribute (constructeur de copie)


Attribute::Attribute (string identifiant )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribute>" << endl;
#endif
	
	ID = identifiant;
	unit="ug/m3";
	description="concentration ";
	if(identifiant=="O3"){
		description+="d'ozone";
	}else if(identifiant=="SO2"){
		description+="de dioxyde de soufre";
	}else if(identifiant=="NO2"){
		description+="de dioxyde d'azote";
	}else if(identifiant=="PM10"){
		description+="de particules fines";
	}
} //----- Fin de Attribute


Attribute::~Attribute ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribute>" << endl;
#endif
} //----- Fin de ~Attribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

