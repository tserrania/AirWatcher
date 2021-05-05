/*************************************************************************
                           IHMProvider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <IHMProvider> (fichier IHMProvider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "IHMProvider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type IHMProvider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void IHMProvider::afficherMenu() const{
	cout<<"Veuillez taper: "<<endl;
	cout<<"		1 pour mesurer l'efficacité d'un capteur."<<endl;
	cout<<"		0 pour quitter."<<endl;
	cout<<endl;
}

void IHMProvider::selectionCleaner() const{
	cout<<"Veuillez rentrer l'identifiant du purificateur à tester: ";
}

void IHMProvider::afficherEfficacite(const map<Attribute,double> & pourcentages, double rayonAction){
	cout<<"Le purificateur a un rayon d'action de "<<rayonAction<<" mètres."<<endl;
}


//------------------------------------------------- Surcharge d'opérateurs
IHMProvider & IHMProvider::operator = ( const IHMProvider & unIHMProvider )
// Algorithme :
//
{
	if(this!=&unIHMProvider){
		utilisateurConnecte=unIHMProvider.utilisateurConnecte;
	}
	return(*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
IHMProvider::IHMProvider ( const IHMProvider & unIHMProvider ):AbstractIHM(unIHMProvider.utilisateurConnecte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <IHMProvider>" << endl;
#endif
} //----- Fin de IHMProvider (constructeur de copie)


IHMProvider::IHMProvider (User & unUser):AbstractIHM(unUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <IHMProvider>" << endl;
#endif
} //----- Fin de IHMProvider


IHMProvider::~IHMProvider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <IHMProvider>" << endl;
#endif
} //----- Fin de ~IHMProvider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

