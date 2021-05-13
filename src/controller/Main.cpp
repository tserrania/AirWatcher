
#include <iostream>
#include "view/IHMProvider.h"
#include "view/IHMAgency.h"
#include "view/IHMIndividual.h"
#include "model/objet/Individual.h"
#include "model/objet/Provider.h"
#include "model/objet/Agency.h"
using namespace std;

int main (void){
	//Service service = new Service();
	string id; string mdp;
	AbstractIHM::menuConnexion();
	Individual *utilisateur=new Individual("joris","1234","01");
	AbstractIHM *ihm(0);
	
	cout<<"Bonjour"<<endl;
	
	if(dynamic_cast<Agency*>(utilisateur)==nullptr && dynamic_cast<Provider*>(utilisateur)==nullptr){
		ihm = new IHMIndividual(*utilisateur);
		cout<<"Individual"<<endl;
	}else if(dynamic_cast<Agency*>(utilisateur)==nullptr && dynamic_cast<Individual*>(utilisateur)==nullptr){
		ihm = new IHMProvider(*utilisateur);
		cout<<"Provider"<<endl;
	}else if(dynamic_cast<Provider*>(utilisateur)==nullptr && dynamic_cast<Individual*>(utilisateur)==nullptr){
		ihm = new IHMAgency(*utilisateur);
		cout<<"Agency"<<endl;
	}else{
		cout<<"L'utilisateur n'existe pas"<<endl;
	}
	
	cout<<"termine"<<endl;
	
	//~ int choix=-1;
	//~ while(choix!=0){
		//~ ihm->afficherMenu();
		//~ int choix=ihm->recupererChoix();
		
		//~ service.executerAlgorithme(choix);
	//~ }
	
	//~ cout<<"Au revoir"<<endl;
	delete ihm;
}
