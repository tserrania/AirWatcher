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
#include "view/IHMAgency.h"

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
	cout<<"		2 pour quitter."<<endl;
}

void IHMAgency::selectionCapteurDefectueux() const{
	cout<<"Veuillez rentrer l'identifiant du capteur à vérifier: ";
}

void IHMAgency::afficherCapteurDefectueux(const string & etatCapteur) const{
	if(etatCapteur=="valide"){
		cout<<"Le capteur fonctionne correctement."<<endl;
	}else if(etatCapteur=="defectueux"){
		cout<<"Le capteur est defectueux."<<endl;
	}else if(etatCapteur=="incertain"){
		cout<<"Le capteur a un comportement anormal. Des vérifications supplémentaires sont nécessaires."<<endl;
	}else{
		cout<<"Le capteur n'a pas été trouvé, veuillez vérifier l'identifiant"<<endl;
	}
	cout<<endl;
}

int IHMAgency::traduireChoix(int choix) const{
	if(choix==1){                              
		selectionCapteurDefectueux();
		string idCapteur=recupererChaine();
		return(1);  //Code correspondant à l'appel du service repérer un capteur défectueux
	}else if(choix==2){
		return(0); //Code correspondant pour quitter l'application
	}else{
		return(-1); //Code correspondant à un choix invalide
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

