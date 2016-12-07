/*
Creado por: Jose Antonio Ruiz.
						Julio Antonio Fresneda.
						Adrian Pelaez.

Practica 4 ED : Iteradores
Universidad de Granada
*/

#ifndef __MUTACION_H
#define __MUTACION_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>

#include "enfermedad.h"
//! Clase mutacion, asociada a la definición de una mutación/SNP
/*! mutacion::mutacion,  .....
 *
 @todo Implementa esta clase, junto con su documentación asociada

*/
using namespace std;

class mutacion {
 private:
  string ID;
  string chr;
  unsigned int pos;
  vector<string> ref_alt;
  vector<string> genes;
  bool common;
  vector<float> caf;
  vector<enfermedad> enfermedades;
  vector<int> clnsig;

 public:

  mutacion();
  mutacion(const mutacion& m);
  mutacion(const string & str);   //para crear objeto mutacion a partir de la cadena que contiene una línea completa del fichero de entrada

  void setID(const string & id);
  void setChr(const string & chr);
  void setPos(const unsigned int & pos);
  void setRef_alt(const vector<string> & ref_alt);
  void setGenes (const vector<string> & genes);
  void setCommon (const bool & common);
  void setCaf (const vector<float> & caf);
  void setEnfermedades (const vector<enfermedad> & enfermedades);
  void setClnsig (const vector<int> & clnsig);

  string getID( ) const;
  string getChr( ) const;
  unsigned int getPos( ) const;
  const vector<string> & getRef_alt () const;
  const vector<string> & getGenes () const;
  bool getCommon () const;
  const vector<float> & getCaf () const;
  const vector<enfermedad> & getEnfermedades () const;
  const vector<int> & getClnsig () const;


  mutacion & operator=(const mutacion & m);
  bool operator==(const mutacion & m) const;
  bool operator<(const mutacion & m) const;      //El orden viene determinado por Chr y pos. El primer criterio es el número de cromosoma. El orden para el número de cromosoma se rige por "1"<"2"<"3"<...<"22"<"X"<"Y"<"MT". Dos mutaciones del mismo cromosoma deben ordenarse según su posición, de menor posición a mayor (orden natural de enteros).
  bool operator>(const mutacion & m) const;

};

  ostream& operator<< ( ostream& os, const mutacion& m);   //Imprimir TODOS los campos del objeto mutación.


#include "mutacion.hxx"
#endif
