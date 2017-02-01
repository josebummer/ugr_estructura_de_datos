/**
Escribe una funcion a la que se quee pase un arbol y un nodo y devuelva el nodo a la derecha
del nodo que se pasa como argumento.
*/

#include <iostream>
#include "bintree.h"
#include <queue>

using namespace std;

template<typename T>
typename bintree<T>::node siguienteNodo(const bintree<T> &A, const typename bintree<T>::node &n){
  typename bintree<T>::node aux;
  typename bintree<T>::node res(0);
  bool sig = false;

  if( !n.null()){
    queue<typename bintree<T>::node> q;
    q.push(A.root());
    while(!q.empty()){
      aux = q.front();
      if(sig){
        return aux;
      }
      if( aux == n ){
        sig = true;
      }
      if( !aux.left().null() ){
        q.push(aux.left());
      }
      if( !aux.right().null() ){
        q.push(aux.right());
      }
      q.pop();
    }
  }
  return res;
}

int main(){
  bintree<int> prueba(7);

  prueba.insert_left(prueba.root(), 1);
  prueba.insert_right(prueba.root(), 9);
  prueba.insert_left(prueba.root().left(), 6);
  prueba.insert_right(prueba.root().left(), 8);
  prueba.insert_right(prueba.root().left().right(), 4);
  prueba.insert_left(prueba.root().right(), 5);

  //      Arbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    /
  // 6    8  5
  //       \
  //       4

  typename bintree<int>::node n = siguienteNodo(prueba,prueba.root().left().right());

  cout << *n << endl;

  return 0;
}
