/*
Implementa una función a la que se le pase una lista de enteros y un entero x de manera que cada vez
que aparezca en una posición ese valor, se inserte x-1 en la posición siguiente.
*/

#include <iostream>
#include <list>

using namespace std;

/**
@brief Busca en la lista el elemento indicado, si lo encuentra, añade elemento-1 a la posicion siguiente donde se encuentra.
@pre la lista debe tener elementos
@param l: lista para buscar el elemento y añadir elemento-1 por cada aparicion
@param n: elemento a buscar
@return Devuelve la lista por referencia MODIFICADA
*/
void insertarValor( list<int> &l , int n ){
  list<int>::iterator it;

  for( it = l.begin(); it != l.end(); ++it ){
    if( *it == n ){
      ++it;
      it = l.insert(it,n-1);
    }
  }
}

int main(){
  list<int> l;
  list<int>::iterator it;

  l.push_back(5);
  l.push_back(3);
  l.push_back(1);
  l.push_back(5);
  l.push_back(8);
  l.push_back(5);

  cout << "La lista es:" << endl;
  for( it = l.begin(); it != l.end(); ++it ){
    cout << *it << " ";
  }
  cout << endl;

  insertarValor(l,5);

  cout << "Ahora la lista es:" << endl;
  for( it = l.begin(); it != l.end(); ++it ){
    cout << *it << " ";
  }
  cout << endl;

}
