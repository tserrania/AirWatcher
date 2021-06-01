/*************************************************************************
                           AbstractIHM  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AbstractIHM> (fichier AbstractIHM.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "view/AbstractIHM.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AbstractIHM::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void AbstractIHM::accueil() const{
	cout<<"Bienvenue dans AirWatcher"<<endl;
	cout<<"Veuillez taper: "<<endl;
	cout<<"		1 pour vous connecter."<<endl;
	cout<<"		2 pour quitter."<<endl;
}

void AbstractIHM::menuConnexion(string & id, string & mdp) const{
	cout<<"identifiant: "<<endl;
	cin>>id;
	cout<<"mot de passe: "<<endl;
	cin>>mdp;
}

int AbstractIHM::recupererChoix() const{
	int choix;
	cin>>choix;
	return(choix);
}

string AbstractIHM::recupererChaine() const{
	string chaine;
	cin>>chaine;
	return(chaine);
}


//------------------------------------------------- Surcharge d'opérateurs
AbstractIHM & AbstractIHM::operator = ( const AbstractIHM & unAbstractIHM )
// Algorithme :
//
{
	if(this!=&unAbstractIHM){
		utilisateurConnecte=unAbstractIHM.utilisateurConnecte;
	}
	return(*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AbstractIHM::AbstractIHM ( const AbstractIHM & unAbstractIHM ): utilisateurConnecte(unAbstractIHM.utilisateurConnecte)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AbstractIHM>" << endl;
#endif
} //----- Fin de AbstractIHM (constructeur de copie)


AbstractIHM::AbstractIHM (const User & unUser):utilisateurConnecte(unUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AbstractIHM>" << endl;
#endif
} //----- Fin de AbstractIHM


AbstractIHM::~AbstractIHM ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AbstractIHM>" << endl;
#endif
} //----- Fin de ~AbstractIHM


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

