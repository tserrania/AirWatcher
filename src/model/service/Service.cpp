/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 2021/05/05
    copyright            : (C) 2021 par B3104-B3113
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <map>
#include "model/objet/Measurement.h"
#include "model/objet/Attribute.h"
#include "model/objet/Sensor.h"
using namespace std;

//------------------------------------------------------ Include personnel
#include "Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Service::Service ( const Service & unService )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service>" << endl;
#endif
} //----- Fin de Service (constructeur de copie)


Service::Service (string csv_attributes, string csv_cleaners, string csv_measurements, string csv_providers, string csv_sensors, string csv_users)
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
    readSensors(csv_attributes, csv_measurements, csv_sensors);
    // TODO: Read users, providers and cleaners
} //----- Fin de Service


Service::~Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Service>" << endl;
#endif
} //----- Fin de ~Service


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Date Service::readDate(ifstream& ifs) {
	string buffer;
	int a,m,j,h,mi,s;
	getline(ifs, buffer, '-');
	a = stoi(buffer);
	getline(ifs, buffer, '-');
	m = stoi(buffer);
	getline(ifs, buffer, ' ');
	j = stoi(buffer);
	getline(ifs, buffer, ':');
	h = stoi(buffer);
	getline(ifs, buffer, ':');
	mi = stoi(buffer);
	getline(ifs, buffer, ';');
	s = stoi(buffer);
	return Date(a,m,j,h,mi,s);
}

void Service::readSensors(string& csv_attributes, string& csv_measurements, string& csv_sensors) {
    ifstream in_attr;
    in_attr.open(csv_attributes);
    map<string, Attribute> attributes;
    if( ! in_attr.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_attributes << ">" << endl;
    } else {
        while (!in_attr.eof()) {
        	string id;
        	string unit;
        	string description;
        	string buffer;
        	getline(in_attr, id, ';');
        	getline(in_attr, unit, ';');
        	getline(in_attr, description, ';');
        	
        	//Ignore everything until the end of the line
        	getline(in_attr, buffer, '\n');
        	Attribute a(id);
        	attributes.insert(pair<string,Attribute>(id, a));
        }
        in_attr.close();
    }
    ifstream in_meas;
    in_meas.open(csv_measurements);
    multimap<string, Attribute> measurements;
    if( ! in_meas.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_measurements << ">" << endl;
    } else {
        while (!in_meas.eof()) {
        	Date date = readDate(in_meas);
        	string sensor_id;
        	string attrib_id;
        	string buffer ;
        	string value;
        	getline(in_meas, sensor_id, ';');
        	getline(in_meas, attrib_id, ';');
        	//Ignore everything until the end of the line
        	getline(in_attr, buffer, '\n');
        	Measurement m(date, attributes.find(attrib_id)->second, stod(value));
        	measurements.insert(pair<string,Measurement>(sensor_id, m));
        }
        in_meas.close();
    }
    ifstream in_sens;
    in_sens.open(csv_sensors);
    if( ! in_sens.is_open( ) ){
        cerr << "Erreur d'ouverture du fichier <" << csv_sensors << ">" << endl;
    } else {
        while (!in_sens.eof()) {
        	string sensor_id;
        	string lat;
        	string lon;
        	string buffer ;
        	getline(in_sens, sensor_id, ';');
        	getline(in_sens, lat, ';');
        	getline(in_sens, lon, ';');
        	//Ignore everything until the end of the line
        	getline(in_attr, buffer, '\n');
        	list<Measurement> ms(measurements.lower_bound(sensor_id), measurements.upper_bound(sensor_id));
        	sensors.push_back(Sensor(sensor_id, Point(stod(lat), stod(lon)),"valid", ms));
        }
        in_sens.close();
    }
}
