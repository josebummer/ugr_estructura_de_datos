/**
Una secuencia guiada sobre un árbol binario de enteros comienza por
la raíz para a continuación, en cada paso, seleccionar el nodo con etiqueta más
pequeña de entre los nodos disponibles en ese momento que no hayan sido listados.
Se entiende por nodo disponible aquel cuyo padre ya ha sido procesado (excluyendo
la raíz).
a) ¿Qué estructura auxiliar utilizarías para almacenar el conjunto de nodos
disponibles? Razona tu respuesta.
 - Utilizaria una cola con prioridad.
b) Implementar una función que permita obtener una secuencia guiada de un árbol
binario.
*/
#include <iostream>
#include "bintree.h"
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;

template<typename T>
class comp{
public:
  bool operator()(typename bintree<T>::node n1, typename bintree<T>::node n2){
    return ( *n1 > *n2 );
  }
};

template<typename T>
void secuenciaGuiada(const bintree<T> &A){
  typename bintree<int>::node aux;
  if( !A.empty() ){
    priority_queue<typename bintree<int>::node,vector<typename bintree<int>::node>, comp<int> > pq;
    pq.push(A.root());
    while( !pq.empty() ){
      aux = pq.top();
      pq.pop();
      cout << *aux << " ";
      if( !aux.left().null() )
        pq.push(aux.left());
      if( !aux.right().null() )
        pq.push(aux.right());
    }
    cout << endl;
  }
}

int main(){
  bintree<int> prueba(21);

  prueba.insert_left(prueba.root(), 6);
  prueba.insert_right(prueba.root(), 5);
  prueba.insert_left(prueba.root().left(), 10);
  prueba.insert_right(prueba.root().left(), 1);
  prueba.insert_left(prueba.root().right(), 7);
  prueba.insert_right(prueba.root().right(), 3);
  prueba.insert_right(prueba.root().right().left(), 2);

  // Creamos el árbol:
  //        21
  //     /    \
  //    6      5
  //  /  \    / \
  // 10  1   7  3
  //         \
  //          2

secuenciaGuiada(prueba);

}
