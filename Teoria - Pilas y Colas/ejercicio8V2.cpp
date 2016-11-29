/*
Implementa una función insertar(Q, pos, x) que inserte un elemento en una cola Q en la posición pos.
La cola debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)
*/

#include <iostream>
#include <queue>

using namespace std;

template<typename T>

/**
@brief Inserta un elemento en una posicion determinada de una cola
@param q: cola a la que se le va a insertar el elemento
@param pos: posicion donde se insertara el nuevo elemento
@param x: elemento a insertar en la cola
*/
void insertar( queue<T> & q , int pos , T x ){
  if( pos >=0 && pos <= q.size() ){                           //Comprobamos si se puede insertar el elemento
    int tam = q.size()+1;
    for( int i = 0; i < tam; i++ ){                         //Recorremos la pila completa mas 1 vez mas
      if( i == pos ){                                       //Si 'pos' == a la posiciones en la que nos encontramos
        q.push(x);                                          //Añadimos 'x' a la cola
      }
      else{                                                 //En caso contrario
        q.push(q.front());                                  //Metemos el primer elemento de la cola al final
        q.pop();                                            //Borramos el primer elemento
      }
    }
  }
}

int main(){
  queue<int> q;

  for( int i = 1; i < 10; i++ ){
    q.push(i);
  }
  insertar(q,4,7);
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
