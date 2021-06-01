
#include <iostream>
#include "view/IHMProvider.h"
#include "view/IHMAgency.h"
#include "view/IHMIndividual.h"
#include "model/objet/Individual.h"
#include "model/objet/Provider.h"
#include "model/objet/Agency.h"
#include "model/service/Service.h"
using namespace std;

const string attributesPath="../../dataset/attributes.csv";
const string cleanersPath="../../dataset/cleaners.csv";
const string measurementsPath="../../dataset/measurements.csv";
const string providersPath="../../dataset/providers.csv";
const string sensorsPath="../../dataset/sensors.csv";
const string usersPath="../../dataset/users.csv";

//~ void connexion(AbstractIHM *ihm, User *utilisateur){
	//~ string id; string mdp;
	//~ while(utilisateur==nullptr){
		//~ ihm->menuConnexion(id,mdp);
		//~ utilisateur=service.authentifier(id,mdp);
		//~ if(utilisateur==nullptr){
			//~ cout<<"Identifiants incorrects, veuillez réessayer"<<endl;
		//~ }
	//~ }
//~ }

//~ void choixIHM(AbstractIHM *ihm, User *utilisateur){
	//~ if(dynamic_cast<Agency*>(utilisateur)==nullptr && dynamic_cast<Provider*>(utilisateur)==nullptr){
		//~ ihm = new IHMIndividual(*utilisateur);
		//~ cout<<"Individual"<<endl;
	//~ }else if(dynamic_cast<Agency*>(utilisateur)==nullptr && dynamic_cast<Individual*>(utilisateur)==nullptr){
		//~ ihm = new IHMProvider(*utilisateur);
		//~ cout<<"Provider"<<endl;
	//~ }else if(dynamic_cast<Provider*>(utilisateur)==nullptr && dynamic_cast<Individual*>(utilisateur)==nullptr){
		//~ ihm = new IHMAgency(*utilisateur);
		//~ cout<<"Agency"<<endl;
	//~ }
//~ }

//Selon choix, qui est un numéro qui dépend à la fois de l'entrée utilisateur et du type d'IHM, on exécute la méthode correspondante
void choixAction(int choix, AbstractIHM *ihm, Service * service, User * utilisateur){
	switch(choix){
		case 1:{
			string idCapteur=ihm->recupererChaine();
			cout<<"Analyse du capteur "<<idCapteur<<endl;
			string etatCapteur=service->checkSensor(idCapteur);
			ihm->afficherCapteurDefectueux(etatCapteur);
		}
			break;
		
		case 2:
			cout<<"Affichage du nombre de points"<<endl;
			ihm->afficherPoints(utilisateur->getPoints());
			break;
		
		case 3:{
			string idCleaner=ihm->recupererChaine();
			cout<<"Efficacité du purificateur "<<idCleaner<<endl;
			pair<map<Attribute, double>, double> res = service->MesurerPerformancePurificateur(idCleaner);
			ihm->afficherEfficacite(res.first, res.second);
		}
			break;
		
		case 0:
			cout<<"Au revoir"<<endl; break;
		
		default:
			cout<<"Choix invalide"<<endl;
	}
}

int main (void){
	Service *service = new Service(attributesPath,cleanersPath,measurementsPath,providersPath,sensorsPath,usersPath);
	cout<<"Service Démarré"<<endl;
	int choix;
	User u("", "");
	AbstractIHM *ihm = new IHMIndividual(u); // Par défaut
	User* utilisateur = nullptr;
	while(true){
		User *utilisateur = nullptr;
		
		ihm->accueil();
		int choix=ihm->recupererChoix();
		if(choix!=1){break;}
		string id; string mdp;
		while(utilisateur==nullptr){
			ihm->menuConnexion(id,mdp);
			utilisateur=service->authentifier(id,mdp);
			if(utilisateur==nullptr){
				cout<<"Identifiants incorrects, veuillez réessayer"<<endl;
			}
		}
		
		cout<<"Bonjour "<<utilisateur->GetID()<<endl;
		
		//choixIHM(ihm,utilisateur);
		delete ihm; 
		if(dynamic_cast<Agency*>(utilisateur)==nullptr && dynamic_cast<Provider*>(utilisateur)==nullptr){
			ihm = new IHMIndividual(*utilisateur);
			cout<<"Individual"<<endl;
		}else if(dynamic_cast<Agency*>(utilisateur)==nullptr && dynamic_cast<Individual*>(utilisateur)==nullptr){
			ihm = new IHMProvider(*utilisateur);
			cout<<"Provider"<<endl;
		}else if(dynamic_cast<Provider*>(utilisateur)==nullptr && dynamic_cast<Individual*>(utilisateur)==nullptr){
			ihm = new IHMAgency(*utilisateur);
			cout<<"Agency"<<endl;
		}
		
		
		choix=-1;
		while(choix!=0){  //Choix vaut 0 lorsque l'utilisateur demande de quitter
			ihm->afficherMenu();  //Affichage de l'ensemble des fonctionnalités disponibles
			choix=ihm->recupererChoix();  //On récupère l'entrée clavier
			if(choix!=-1){
				choix=ihm->traduireChoix(choix); //On interprète l'entrée utlisateur pour appeler le bon service
				choixAction(choix,ihm,service,utilisateur);
			}else{
				cout<<"Choix invalide"<<endl;
			}
		}
	}
	delete ihm; 
	delete service;
	return(0);
}
