/*************************************************************************
                           IHMIndividual  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <IHMIndividual> (fichier IHMIndividual.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "view/IHMIndividual.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type IHMIndividual::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void IHMIndividual::afficherMenu() const{
	cout<<"Veuillez taper: "<<endl;
	cout<<"		1 pour obtenir votre nombre de points."<<endl;
	cout<<"		2 pour quitter."<<endl;
}

void IHMIndividual::afficherPoints(int points) const{
	cout<<"Vous avez obtenu un total de "<<points<<" points."<<endl;
	cout<<endl;
}

int IHMIndividual::traduireChoix(int choix) const{
	if(choix==1){
		return(2);  //Code correspondant au service pour afficher le nombre de points
	}else if(choix==2){
		return(0); //Code correspondant pour quitter l'application
	}else{
		return(-1); //Code correspondant à un choix invalide
	}
}


//------------------------------------------------- Surcharge d'opérateurs
IHMIndividual & IHMIndividual::operator = ( const IHMIndividual & unIHMIndividual )
// Algorithme :
//
{
	if(this!=&unIHMIndividual){
		utilisateurConnecte=unIHMIndividual.utilisateurConnecte;
	}
	return(*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
IHMIndividual::IHMIndividual ( const IHMIndividual & unIHMIndividual ):AbstractIHM(unIHMIndividual.utilisateurConnecte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <IHMIndividual>" << endl;
#endif
} //----- Fin de IHMIndividual (constructeur de copie)


IHMIndividual::IHMIndividual (User & unUser):AbstractIHM(unUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <IHMIndividual>" << endl;
#endif
} //----- Fin de IHMIndividual


IHMIndividual::~IHMIndividual ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <IHMIndividual>" << endl;
#endif
} //----- Fin de ~IHMIndividual


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

