/*
Usando una pila y una cola, implementa una función que compruebe si un string es un palı́ndromo.
*/

#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

/**
@brief COmprueba si un string pasado como argumento es palindromo
@param s: string que contiene la cadena a comprobar
@pre la cadena a comprobar no puede estar vacia
@return devuelve true si el contenido del string es palindromo y false en caso contrario
*/
bool palindromo( const string & s ){
  stack<char> p;
  queue<char> q;
  for(int i = 0; i < s.size(); i++){                  //Recorremos el string completo
      p.push(s[i]);
      q.push(s[i]);
  }
  while( !p.empty() || !q.empty()){      //Comparamos los elementos de la pila con la cola
    if( p.top() == q.front() ){                       //En el caso de que sean iguales, los borramos y seguimos con la comprobacion
      p.pop();
      q.pop();
    }
    else{                                             //Si no son iguales devolvemos false;
      return false;
    }
  }
  if( p.empty() && q.empty() )                        //Al finalizar comprobamos si tanto la pila como la cola se han quedado vacias
    return true;                                      //En caso afirmativo es palindromo
  else
    return false;                                     //En caso contrario no lo es
}

int main(){
  string f = "aaa";

  if( palindromo(f) )
    cout << "Es palindromo" << endl;
  else
    cout << "NOO es palindromo" << endl;
}
