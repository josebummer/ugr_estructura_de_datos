/*
Construye una función a la que se le pase el nobmre de un fichero y devuelva un map que contenga
las palabras que aparecen y el número de veces que aparece cada una.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

typedef map<string,int> MapaPalabras;

MapaPalabras numPalabras(const string &nomfich){
    ifstream fich;
    string palabra;
    MapaPalabras res;

    fich.open(nomfich.c_str());
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

  mapa = numPalabras("prueba.txt");

  MapaPalabras::iterator it;

  for ( it = mapa.begin(); it != mapa.end(); ++it ){
    cout << "La palabra " << it->first << " aparece " << it->second << " veces." << endl;
  }

  return 0;
}
