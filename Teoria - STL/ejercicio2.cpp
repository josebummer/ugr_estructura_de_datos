/*
Construye una función que dado el map del ejercicio anterior devuelva un multimap que nos permita
consultar las palabras que aparecen un número determinado de veces.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

using namespace std;

typedef map<string,int> MapaPalabras;
typedef multimap<string,int>  MultiMapaPalabras;

/**
@brief Transforma un mapa en un multimapa
@param m: mapa a transformar en multimapa
@return devuelve un multimapa con la informacion que tenia el mapa
*/
MultiMapaPalabras tranformar(MapaPalabras m){
    MultiMapaPalabras res;
    MapaPalabras::iterator it;

    for( it = m.begin(); it != m.end(); ++it){
      res.insert(pair<string,int>(it->first,it->second));
    }
    return res;
}
/**
@brief Crea un mapa con las palabras que hay en un fichero y guarda el numero de apariciones
@param nomfich: nombre del fichero donde se encuentran las palabras
@return devuelve un mapa con las palabras que aparecen en el fichero y el numero de veces que aparece cada una
*/
MapaPalabras numPalabras(char *nomfich){
    ifstream fich;
    string palabra;
    MapaPalabras res;

    fich.open(nomfich);
    fich >> palabra;
    while(!fich.eof()){
      res[palabra] += 1;
      fich >> palabra;
    }
    fich.close();

    return res;
}

int main(){
  MapaPalabras mapa;
  MultiMapaPalabras multi;

  mapa = numPalabras("prueba.txt");
  multi = tranformar(mapa);

  MultiMapaPalabras::iterator it;

  for ( it = multi.begin(); it != multi.end(); ++it ){
    cout << "La palabra " << it->first << " aparece " << it->second << " veces." << endl;
  }

  return 0;
}
