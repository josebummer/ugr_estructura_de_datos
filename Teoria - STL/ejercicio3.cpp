/*
Un método de encriptación basado en un código consiste en transformar cada letra del alfabeto por
otra. Implementa una función encripta la que se le pasa una cadena de caracteres y un map <
char, char > con el código y que devuelva la cadena encriptada.
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

int main(){
  MapaPalabras m;
  string cadena = "albaricoque";
  string encriptada;

  construirMapa(m);
  encriptada = encripta(cadena,m);

  cout << "La cadena es: " << cadena << " y encriptada es: " << encriptada << endl;
}
