/*
Implementa el TDA pila usando dos colas. ¿Qué orden de eficiencia tienen las operaciones push y pop?
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T>

//PARA MEJORAR, METER UN BOOL PARA INDICAR CON QUE COLA ESTAMOS TRABAJANDO Y ASI INSERTAR O ELIMINAR EN LA QUE TRABAJAMOS
//Y NOS AHORRAMOS EL VOLCADO DE UNA COLA A OTRA.


class Pila{
private:
  queue<T> ord;
  queue<T> al;
public:
  /**
  @brief Nos indica si la pila esta vacia
  @return Devuelve true si esta vacia, false en caso contrario
  */
  bool empty() const{
    if(ord.empty())
      return true;
    return false;
  }
  /**
  @brief Nos indica el tamaño de la pila
  @return Tamaño de la cola
  */
  int size() const{
    return ord.size();
  }
  /**
  @brief Nos da el primer ultimo elemento insertado a la pila.
  @return Devuelve el ultimo elemento insertado en la pila
  */
  T top() const{
    if(!(this->empty()))
      return ord.back();
  }
  /**
  @brief Inserta un elemento a la pila
  @param x: Elemento a insertar en la pila
  */
  void push( T x ){                             //ORDEN DE EFICIENCIA = O(1)
    ord.push(x);
  }
  /**
  @brief Elimina el ultimo elemento de la pila
  */
  void pop(){                                 //ORDEN DE EFICIENCIA = O(n)
    if ( !(this->empty() )){
      int tam = ord.size()-1;
      int i = 0;
      while( i < tam ){
        al.push(ord.front());
        ord.pop();
        i++;
      }
      ord.pop();
      while( !al.empty() ){
        ord.push(al.front());
        al.pop();
      }
    }
  }
  /**
  @brief Compara si la pila actual es menor que la pila que se le pasa como parametro.
  @param otra: pila a comparar con la actual
  @pre Las pilas deben tener elementos
  @return devuelve true si la pila actual es menor que la que se le pasa como parametro, false en caso contrario
  */
  bool operator<(const Pila & otra) const{
    return (ord < otra.ord);
  }
  /**
  @brief Compara si la pila actual es igual que la pila que se pasa como parametro
  @param otra: pila a comparar con la actual
  @pre Las pilas deben tener elementos
  @return devuelve true si las dos pilas son iguales, false en caso contrario
  */
  bool operator==(const Pila & otra) const{
    return (ord == otra.ord);
  }

};

int main(){
  Pila<int> a , b;

  for ( int i = 0; i < 100; i++){
    a.push(i);
  }
  b = a;
  while ( !a.empty() ){
    cout << a.top() << endl;
    a.pop();
  }
  a.push(1);
  if ( a == b ){
    cout << "Las dos pilas son iguales." << endl;
  }
  else{
    cout << "Las dos pilas NO son iguales." << endl;
  }
  a = b;
  if ( a == b ){
    cout << "Las dos pilas son iguales." << endl;
  }
  else{
    cout << "Las dos pilas NO son iguales." << endl;
  }
}
