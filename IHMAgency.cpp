/*************************************************************************
                           IHMAgency  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <IHMAgency> (fichier IHMAgency.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "IHMAgency.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type IHMAgency::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void IHMAgency::afficherMenu() const{
	cout<<"Veuillez taper: "<<endl;
	cout<<"		1 pour vérifier si un capteur est défectueux."<<endl;
	cout<<"		0 pour quitter."<<endl;
	cout<<endl;
}

void IHMAgency::selectionCapteurDefectueux() const{
	cout<<"Veuillez rentrer l'identifiant du capteur à vérifier: ";
}

void IHMAgency::afficherCapteurDefectueux(const string & etatCapteur) const{
	if(etatCapteur=="inexistant"){
		cout<<"L'identifiant tapé n'est pas présent dans la base de données"<<endl;
	}else if(etatCapteur=="valide"){
		cout<<"Le capteur fonctionne correctement."<<endl;
	}else if(etatCapteur=="defectueux"){
		cout<<"Le capteur est defectueux."<<endl;
	}else if(etatCapteur=="incertain"){
		cout<<"Le capteur a un comportement anormal. Des vérifications supplémentaires sont nécessaires."<<endl;
	}
}


//------------------------------------------------- Surcharge d'opérateurs
IHMAgency & IHMAgency::operator = ( const IHMAgency & unIHMAgency )
// Algorithme :
//
{
	if(this!=&unIHMAgency){
		utilisateurConnecte=unIHMAgency.utilisateurConnecte;
	}
	return(*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
IHMAgency::IHMAgency ( const IHMAgency & unIHMAgency ):AbstractIHM(unIHMAgency.utilisateurConnecte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <IHMAgency>" << endl;
#endif
} //----- Fin de IHMAgency (constructeur de copie)


IHMAgency::IHMAgency (User & unUser):AbstractIHM(unUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <IHMAgency>" << endl;
#endif
} //----- Fin de IHMAgency


IHMAgency::~IHMAgency ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <IHMAgency>" << endl;
#endif
} //----- Fin de ~IHMAgency


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

