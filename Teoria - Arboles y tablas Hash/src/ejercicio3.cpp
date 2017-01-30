/**
Escribe una funci ́on que realice la reflexi ́on de un a  ́ rbol binario. Es decir, una funci ́on a la que se le
pase un a  ́ rbol y se modifique de forma que para cada nodo su hijo a la izquierda pase a ser el derecho
y viceversa.
*/

#include <iostream>
#include "bintree.h"

using namespace std;

template<typename T>
void reflexion( bintree<T> &A ){
  bintree<T> auxiz;
  bintree<T> auxder;

  if ( !A.empty() ){
    A.prune_left(A.root(),auxiz);
    A.prune_right(A.root(),auxder);

    reflexion(auxiz);
    A.insert_right(A.root(),auxiz);

    reflexion(auxder);
    A.insert_left(A.root(),auxder);
  }
}

int main(){
  bintree<int> prueba(7);

  prueba.insert_left(prueba.root(), 1);
  prueba.insert_right(prueba.root(), 9);
  prueba.insert_left(prueba.root().left(), 6);
  prueba.insert_right(prueba.root().left(), 8);
  prueba.insert_left(prueba.root().left().right(), 3);
  prueba.insert_right(prueba.root().left().right(), 4);
  prueba.insert_left(prueba.root().right(), 5);

  // Creamos el árbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    /
  // 6    8  5
  //     / \
  //    3   4

  cout << "Antes de realizar el cambio:" << endl;
  for( typename bintree<int>::preorder_iterator it = prueba.begin_preorder(); it != prueba.end_preorder(); ++it ){
    cout << *it << endl;
  }

  reflexion(prueba);

  cout << endl << "Despues de realizar el cambio:" << endl;
  for( typename bintree<int>::preorder_iterator it = prueba.begin_preorder(); it != prueba.end_preorder(); ++it ){
    cout << *it << endl;
  }
}
