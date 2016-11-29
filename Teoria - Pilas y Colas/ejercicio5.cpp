/*
Se llama expresión en postfijo a una expresión matemática en la que cada operación aparece con sus
dos operandos seguidos por el operador. Por ejemplo: 2 3 + 5 * Escribe un programa que evalue una
expresión en postfijo.
*/

#include <iostream>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

/**
@brief Calcula una expresion matematica en postfijo
@param c: string con la expresion en postfijo
@pre la expresion en postfijo debe estar sintacticamente correcta
@return devuelve un entero con el resultado
*/
int resultado( const string & c ){
  stack<int> s;
  int der;
  int iz;
  for( int i = 0; i < c.size(); i++ ){              //Recorremos el string elemento por elemento
    if( c[i] >= '0' && c[i] <= '9' ){               //Comprobamos si es un numero
      s.push((int)c[i]-(int)'0');                   //Si lo es lo introducimos en la pila
    }
    else{                                           //Si no lo es, calculamos la operacion que pida
      der = s.top();
      s.pop();
      iz = s.top();
      s.pop();
      switch (c[i]) {
        case '+':
          s.push(iz+der);
        break;
        case '-':
          s.push(iz-der);
        break;
        case '*':
          s.push(iz*der);
        break;
        case '/':
          s.push(iz/der);
        break;
        case '^':
          s.push(pow(iz,der));
        break;
      }
    }
  }
  return s.top();                                  //Devolvemos el valor resultante de las operaciones
}
int main(){
  string a = "53^2*2/9+";

  cout << "Resultado: " << resultado(a) << endl;
}
