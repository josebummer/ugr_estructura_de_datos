/*
Construye una función a la que se se le pase una pila P de tipo T y dos elementos x,y de tipo T y que
modifique la pila de forma que todas las veces que aparezca x se substituya por y (quedando la pila en
el mismo estado en el que estaba anteriormente). Para este ejercicio no se podrán utilizar iteradores.
*/


#include <iostream>
#include <stack>

using namespace std;

template<typename T>

/**
@brief Cambia un elemento de la pila por otro elemento indicado.
@param s: pila que contiene los datos donde vamos a intercambiar el/los elemento/s
@param x: elemento a cambiar en la pila
@param y: elemento que va a sustuir al otro elemento en la pila
@return devuelve por referencia la pila con los cambios realizados
*/
void cambioElementos( stack<T> & s , T x , T y ){
  if( !s.empty() ){
    stack<T> aux;
    while( !s.empty() ){
      if( s.top() == x ){
        aux.push(y);
        s.pop();
      }
      else{
        aux.push(s.top());
        s.pop();
      }
    }
    while( !aux.empty() ){
      s.push(aux.top());
      aux.pop();
    }
  }
}

int main(){
  stack<int> a;

  for ( int i = 0; i < 10; i++){
    a.push(i);
  }

  cambioElementos(a , 5 , 9);

  while ( !a.empty() ){
    cout << a.top() << endl;
    a.pop();
  }

}
