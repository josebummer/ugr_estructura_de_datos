/*
Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas de
caracteres que tengan más vocales y que en caso de igualdad salgan por orden alfabético.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class comp{
public:
  /**
  @brief operador que utilizaremos para la cola con prioridad, para comparar el numero de vocales de una cadena y si es igual, ordenarla alfabeticamente
  @param a: string a comparar con el parametro 'b'
  @param b: string a comparar con el parametro 'a'
  @return devuelve true si se cumplen las condiciones especificadas y false en caso contrario
  */
  bool operator() ( const string & a , const string & b ){
    int vocalesa = 0;
    int vocalesb = 0;

    for( int i = 0; i < a.size(); i++){
      if( a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' ){
        vocalesa++;
      }
    }

    for( int i = 0; i < b.size(); i++){
      if( b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u' ){
        vocalesb++;
      }
    }

    if( vocalesa < vocalesb ){
      return true;
    }
    else if( vocalesa > vocalesb ){
      return false;
    }
    else{
      return (a>b);
    }
  }
};

int main(){
  priority_queue<string, vector<string>, comp> pq;
  string a = "jirafa";
  string b = "adios";
  string c = "muy buenas";
  string d = "aeiou";
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
