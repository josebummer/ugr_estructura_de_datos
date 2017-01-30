/*
Escribe una funcion que acepte un valor de tipo node y un arbol general T y devuelva el nivel del
nodo en el arbol.
*/
#include <iostream>
#include <math.h>
#include "bintree.h"

using namespace std;

template<typename T>
int profundidad(const typename bintree<T>::node &n, const bintree<T> & A){
  int prof = 0;
  typename bintree<T>::node aux=n;

  while( A.root() != aux ){
    prof++;
    aux = aux.parent();
  }
  return prof;
}

int main(){
  bintree<int> prueba(7);
  bintree<int>::node n(8);
  int resultado;

  prueba.insert_left(prueba.root(), 1);
  prueba.insert_right(prueba.root(), 9);
  prueba.insert_left(prueba.root().left(), 6);
  prueba.insert_right(prueba.root().left(), 8);
  prueba.insert_right(prueba.root().left().right(), 4);
  prueba.insert_left(prueba.root().right(), 5);

  // Creamos el árbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    /
  // 6    8  5
  //       \
  //       4

resultado = profundidad(prueba.root().left().right().right(),prueba);

cout << resultado << endl;

}
