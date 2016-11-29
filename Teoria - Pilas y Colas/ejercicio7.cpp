/*
Implementa una función insertar(P, pos, x) que inserte un elemento en una pila P en la posición pos.
La pila debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)
*/

#include <iostream>
#include <stack>

using namespace std;

template<typename T>

/**
@brief Inserta un elemento en una posicion determinada de una pila
@param p: Pila a la que se le va a insertar el elemento
@param pos: posicion donde se insertara el nuevo elemento
@param x: elemento a insertar en la pila
*/
void insertar( stack<T> & p , int pos , T x ){
  if( pos >=0 && pos <= p.size() ){                           //Comprobamos si se puede insertar el elemento
    stack<T> aux;                                             //Creamos una pila auxiliar donde guardaremos los elementos hasta 'pos'
    for ( int i = 0; i < pos; i++ ){                          //Guardamos los elementos en la pila auxiliar
      aux.push(p.top());
      p.pop();
    }
    p.push(x);                                              //Insertamos el nuevo elemento
    while(!aux.empty()){                                  //Rellenamos de nuevo la pila con los datos que tenia
      p.push(aux.top());
      aux.pop();
    }
  }
}

int main(){
  stack<int> p;

  for( int i = 1; i < 10; i++ ){
    p.push(i);
  }
  insertar(p,4,3);
  while(!p.empty()){
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;
}
