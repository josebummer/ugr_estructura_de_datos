/*
Implementa una función que, dada una lista l de tipo T y un elemento x de tipo T, elimine el elemento
x de todas las posiciones en las que aparezca en l. Por ejemplo: si x = 1 y l = (2, 1, 1, 1, 1, 5, 3) el
resultado deberı́a ser (2, 5, 3)
*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>

/**
@brif Elimina todas las apariciones del elemento que se pasa como argumento en la lista que se pasa como argumento
@param l: lista con los elementos y donde vamos a borrar el elemento. SE MODIFICA
@param elem: elemento a eliminar de la lista
@return devuelve por referencia la propia lista pasada como parametro modificada
*/
void eliminarElemento( list<T> &l, const T &elem){
  typename list<T>::iterator it;

  for( it = l.begin(); it != l.end(); ++it ){
    if( *it == elem ){
      it = l.erase(it);
      it--;
    }
  }
}

int main(){
  list<int> l;
  list<int>::iterator it;

  l.push_back(2);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(5);
  l.push_back(3);

  eliminarElemento(l,1);

  for( it = l.begin(); it != l.end(); ++it ){
      cout << *it << endl;
  }
}
