/*
Construye una funcion que determine si un arbol binario es completo.
*/
#include <iostream>
#include "bintree.h"
#include <cmath>

using namespace std;

int max(int uno,int dos){
  int res = (uno < dos)?dos:uno;
  return res;
}

template<typename T>
int altura(const bintree<T> &A, typename bintree<T>::node n){
  if( !n.null() ){
    return (1+max(altura(A,n.left()),altura(A,n.right())));
  }
  else return -1;
}

template<typename T>
bool esArbolCompleto(const bintree<T> &A){
  if( (pow(2,altura(A,A.root())+1)-1) == A.size() ){
    return true;
  }
  return false;
}

int main(){
  bintree<int> prueba(7);

  prueba.insert_left(prueba.root(), 1);
  prueba.insert_right(prueba.root(), 9);
  prueba.insert_left(prueba.root().left(), 6);
  prueba.insert_right(prueba.root().left(), 8);
  // prueba.insert_right(prueba.root().left().right(), 4);
  prueba.insert_left(prueba.root().right(), 5);
  prueba.insert_right(prueba.root().right(), 4);

  //      Arbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    / \
  // 6    8  5  4

  bool completo = esArbolCompleto(prueba);

  if(completo){
    cout << "El arbol es completo." << endl;
  }
  else{
    cout << "El arbol no es completo." << endl;
  }

  cout << "Altura: " << altura(prueba,prueba.root()) << endl;
}
