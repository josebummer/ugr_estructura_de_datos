/*
Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas de
caracteres más largas y que en caso de igualdad salgan por orden alfabético.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class comp{
public:
  /**
  @brief operador que utilizaremos para la cola con prioridad, para comparar el numero de elementos de una cadena y si es igual, ordenarla alfabeticamente
  @param a: string a comparar con el parametro 'b'
  @param b: string a comparar con el parametro 'a'
  @return devuelve true si se cumplen las condiciones especificadas y false en caso contrario
  */
  bool operator() ( const string & a , const string & b ){
    if( a.size() < b.size() ){
      return true;
    }
    else if( a.size() > b.size() ){
      return false;
    }
    else{
      return (a>b);
    }
  }
};

int main(){
  priority_queue<string, vector<string>, comp> pq;
  string a = "hola";
  string b = "adios";
  string c = "muy buenas";
  string d = "pepe";
  pq.push(a);
  pq.push(b);
  pq.push(c);
  pq.push(d);

  while(!pq.empty()){
    cout << pq.top() << endl;
    pq.pop();
  }
  cout << endl;
}
