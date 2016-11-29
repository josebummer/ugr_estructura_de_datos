/*
Implementa un función para determinar si una expresión contenida en un string tiene una configuración
de paréntesis correcta. Debe tener un orden lineal.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
@brief Este metodo comprueba si la distribucion de parentesis en un string esta correctamente.
@param s: frase que se le pasa al metodo para comprobar los parentesis
@return devuelve true si la frase tiene correctamente los parentesis y false en caso contrario
*/
bool parentesisCorrectos( const string & s  ){
  stack<char> aux;
  int i = 0;
  while(i < s.size()){
    if(s[i] == '('){
      aux.push(s[i]);
    }
    else if(s[i] == ')'){
      if(aux.empty()){
        return false;
      }
      aux.pop();
    }
    i++;
  }
  if(aux.empty()){
    return true;
  }
  return false;
}

int main(){
  string frase = "(5+6)+(7-(8+15))";

  cout << "La frase es:" << endl;
  cout << frase << endl << endl;
  if(parentesisCorrectos(frase)){
    cout << "La frase tiene los parentesis correctamente." << endl;
  }
  else{
    cout << "La frase no tiene correctamente distribuidos los parentesis" << endl;
  }
}
