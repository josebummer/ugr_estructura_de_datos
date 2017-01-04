/*
Creado por: Jose Antonio Ruiz.

Practica 6 ED :
Universidad de Granada
*/

#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unistd.h>
#include "clinvar.h"

using namespace std;

int main(){
	clinvar c;
	list<string> l;
	set<string> s;
	char a;

  c.load("clinvar_20160831.vcf");
	cout << "Fichero leido" << endl << endl;

	cout << "Mostramos las mutaciones ordenadas por cromosoma/posicion:" << endl << "PULSA INTRO PARA EJECUTAR" << endl;
	cin.get();
	for( clinvar::iterator it = c.begin(); it != c.end(); ++it ){
		cout << *it;
	}

	string ID = "rs878854652";
	cout << endl << "Busqueda de la mutacion con ID: " << ID << " :" << endl << "PULSA INTRO PARA EJECUTAR" << endl;
	cin.get();
	clinvar::iterator it2 = c.find_Mut(ID);
	if( it2 != c.end() ){
		cout << *it2;
	}
	else{
		cout << "No existe la mutacion con ID: " << ID << endl;
	}

	string gen = "RER1:11079";
	cout << endl << "Busqueda de las mutaciones respecto el gen: " << gen << " :" << endl << "PULSA INTRO PARA EJECUTAR" << endl;
	cin.get();
	s = c.getMutacionesGen(gen);
	for( set<string>::iterator it = s.begin(); it != s.end(); ++it ){
		cout << *it << endl;
	}

	cout << endl << "Enfermedades de la base de datos:" << endl << "PULSA INTRO PARA EJECUTAR" << endl;
	cin.get();
	for( clinvar::enfermedad_iterator it = c.ebegin(); it != c.eend(); ++it ){
		cout << it->second << endl;
	}

	string enf = "C1838867:556500";
	cout << endl << "Mutaciones asociadas a la enfermedad: " << enf << endl << "PULSA INTRO PARA EJECUTAR" << endl;
	cin.get();
	s = c.getMutacionesEnf(enf);
	for( set<string>::iterator it = s.begin(); it != s.end(); ++it ){
		cout << *it << endl;
	}

	string nom = "cancer";
	cout << endl << "Enfermedades que contienen en el nombre: " << nom << endl << "PULSA INTRO PARA EJECUTAR" << endl;
	cin.get();
	l = c.getEnfermedades(nom);
	for( list<string>::iterator it = l.begin(); it != l.end(); ++it ){
		cout << *it << endl;
	}

	set<mutacion,ProbMutaciones> s2;
	nom = "cancer";
	int k = 7;
	cout << endl << k << " Mutaciones que tienen como enfermedad a: " << nom << " y ordenadas por mayor probabilidad" << endl;
	cout << "PULSA INTRO PARA EJECUTAR" << endl;
	cin.get();
	s2 = c.topKMutaciones(k,nom);
	for( set<mutacion,ProbMutaciones>::iterator it = s2.begin(); it != s2.end(); ++it ){
		cout << *it << endl;
	}

  return 0;
}
