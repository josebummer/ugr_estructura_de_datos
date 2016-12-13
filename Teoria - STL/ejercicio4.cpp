/*
Implementa una función desencripta que haga el proceso inverso al del ejercicio anterior.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<char,char> MapaPalabras;

/**
@brief Construye el mapa para encriptar una cadena
@param m: mapa a crear
@pre el mapa que se pasa como parametro debe estar vacio
@return devuelve el propio mapa como referencia con los cambios necesarios
*/
void construirMapa(MapaPalabras &m){
  char j = 's';

  for( char x = 'a'; x != 'z'+1; x++,j++ ){
    m[x] = j;
    if( j == 'z'){
      j = 'a'-1;
    }
  }
}

/**
@brief Construye el mapa para desencriptar una cadena
@param m: mapa a crear
@pre el mapa que se pasa como parametro debe estar vacio
@return devuelve el propio mapa como referencia con los cambios necesarios
*/
void construirMapaDes(MapaPalabras &m){
  char j = 'i';

  for( char x = 'a'; x != 'z'+1; x++,j++ ){
    m[x] = j;
    if( j == 'z'){
      j = 'a'-1;
    }
  }
}

/**
@brief Encripta una cadena usando un mapa determinado
@param cad: cadena que se va a encriptar
@param m: mapa donde se encuentra el metodo de encriptamiento ha utilizar
@pre el mapa que se pasa como parametro debe contener el algoritmo de encriptacion
@return devuelve un string con el contenido de la cadena encriptada
*/
string encripta(const string& cad , const MapaPalabras &m){
  string res;
  MapaPalabras::const_iterator it;

  for( int i = 0; i < cad.size(); i++ ){
    it = m.find(cad[i]);
    res.push_back(it->second);
  }
  return res;
}

/**
@brief Desencripta una cadena usando un mapa determinado
@param cad: cadena que se va a desencriptar
@param m: mapa donde se encuentra el metodo de desencriptamiento ha utilizar
@pre el mapa que se pasa como parametro debe contener el algoritmo de desencriptacion
@return devuelve un string con el contenido de la cadena desencriptada
*/
string desencripta(const string& cad , const MapaPalabras &m){
  string res;
  MapaPalabras::const_iterator it;

  for( int i = 0; i < cad.size(); i++ ){
    it = m.find(cad[i]);
    res.push_back(it->second);
  }
  return res;
}

int main(){
  MapaPalabras me,md;
  string cadena = "albaricoque";
  string encriptada;
  string desencriptada;

  construirMapa(me);
  construirMapaDes(md);
  encriptada = encripta(cadena,me);
  desencriptada = desencripta(encriptada,md);

  cout << "La cadena es: " << cadena << " y encriptada es: " << encriptada << endl;
  cout << "La volvemos a desencriptar y ahora es: " << desencriptada << endl;
}
