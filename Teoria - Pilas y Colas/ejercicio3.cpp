/*
Implementa un TDA cola usando como representación dos pilas.
*/

#include <iostream>
#include <stack>
#include <iterator>

using namespace std;

template<typename T>

class Cola{
private:
  stack<T> f;                             //va a contener los elementos
  stack<T> b;                             //lo utilizaremos cuando sea necesario para mover los elementos
public:
  /**
  @brief Nos indica si la cola esta vacia
  @return Devuelve true si esta vacia, false en caso contrario
  */
  bool empty() const{
    if(f.empty())
      return true;
    return false;
  }
  /**
  @brief Nos indica el tamaño de la cola
  @return Tamaño de la cola
  */
  int size() const{
    return f.size();
  }
  /**
  @brief Nos da el primer elemento insertado a la cola.
  @return Devuelve el primer elemento insertado en la cola
  */
  T front(){
    T res;
    if(!(this->empty())){
      while( !f.empty() ){                 //rellenamos la pila axuiliar
        b.push(f.top());
        f.pop();
      }
      res = b.top();
      while( !b.empty() ){                 //rellenamos la pila con el orden normal
        f.push(b.top());
        b.pop();
      }
      return res;
    }
  }
  /**
  @brief Nos da el ultimo elemento insertado a la cola.
  @return Devuelve el ultimo elemento insertado en la cola
  */
  T back() const{
    if(!(this->empty())){
      return f.top();
    }
  }
  /**
  @brief Inserta un elemento a la cola
  @param x: Elemento a insertar en la cola
  */
  void push( T x ){
    f.push(x);                                //añadimos el elemento a la pila ordenada normalmente
  }
  /**
  @brief Elimina el primer elemento de la cola
  */
  void pop(){
    if ( !(this->empty() )){
      while( !f.empty() ){                 //rellenamos la pila auxiliar
        b.push(f.top());
        f.pop();
      }
      b.pop();
      while( !b.empty() ){
        f.push(b.top());
        b.pop();
      }
    }
  }
  /**
  @brief Compara si la cola actual es menor que la cola que se le pasa como parametro.
  @param otra: cola a comparar con la actual
  @pre Las colas deben tener elementos
  @return devuelve true si la cola actual es menor que la que se le pasa como parametro, false en caso contrario
  */
  bool operator<(const Cola & otra) {
  return (f < otra.f);
  }
  /**
  @brief Compara si la cola actual es igual que la cola que se pasa como parametro
  @param otra: cola a comparar con la actual
  @pre Las colas deben tener elementos
  @return devuelve true si as dos colas son iguales, false en caso contrario
  */
  bool operator==(const Cola & otra) const{
  return (f == otra.f);
  }

};

int main(){
  Cola<int> b , c;

  cout << "COLA CREADA CON 2 PILAS:" << endl;
  for(int i =0;i<10;i++){
    b.push(i);
  }
  cout << b.front() << endl << b.back() << endl;
  b.pop();
  cout << b.front() << endl << b.back() << endl;
  c.push(5);
  if ( b == c ){
    cout << "Las dos colas son iguales." << endl;
  }
  else{
    cout << "Las dos colas NO son iguales." << endl;
  }

  c = b;

  if ( b == c ){
    cout << "Las dos colas son iguales." << endl;
  }
  else{
    cout << "Las dos colas NO son iguales." << endl;
  }
}
