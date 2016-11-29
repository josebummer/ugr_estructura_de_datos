/*
Un tipo ventana es un tipo de dato que permite insertar un elemento, mover derecha, mover izquierda,
borrar elemento y que se implementa usando dos pilas. Implementa ese tipo de dato con las operacio-
nes comentadas.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template<typename T>

class Ventana{
private:
  stack<T> iz;                            //Sera la parte izquierda del cursor
  stack<T> der;                           //Parte derecha del cursor
public:
  /**
  @brief Inserta un elemento a la ventana.
  @param x: elemento a insertar
  */
  void insertar( T x ){
    iz.push(x);
  }
  /**
  @brief mueve el cursor una posicion a la derecha
  */
  void moverDerecha(){
    if( !der.empty() ){
      iz.push(der.top());
      der.pop();
    }
  }
  /**
  @brief mueve el cursor una posicion a la izquierda
  */
  void moverIzquierda(){
    if( !iz.empty() ){
      der.push(iz.top());
      iz.pop();
    }
  }
  /**
  @bref elimina el elemento que esta en la izquierda del cursor
  */
  void borrar(){
    if( !iz.empty() ){
      iz.pop();
    }
  }
  /**
  @brief metodo prueba para mostrar el contenido. (elimina el contenido)
  */
  void mostrar(){
    while( !der.empty()){
      cout << der.top();
      der.pop();
    }
    while( !iz.empty()){
      cout << iz.top();
      iz.pop();
    }
    cout << endl;
  }
};

int main(){
  Ventana<char> v;

  v.insertar('h');
  v.insertar('o');
  v.insertar('l');
  v.insertar('a');

  v.moverIzquierda();

  v.insertar('i');
  v.insertar('t');

  v.moverDerecha();
  v.insertar('s');

  v.mostrar();
  return 0;

}
