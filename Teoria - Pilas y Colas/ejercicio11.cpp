/*
Implementa una cola con prioridad de un tipo struct con (apellidos, nombre, prioridad) de forma que
los datos salgan de acuerdo a ese tercer campo prioridad.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Persona{
  string apellidos;
  string nombre;
  /**
  @brief Operador que va ha ordenar a las personas, que en este caso ordena por el tamaño del nombre
  @param a: persona a comparar con la persona 'b'
  @param b: persona a comparar con la persona 'a'
  @return devuelve true si el nombre de la persona 'a' es menor, false si es mayor, y si son iguales ordena alfabeticamente
  */
  bool operator() (const Persona & a , const Persona & b){
    if( a.nombre.size() < b.nombre.size() ){
      return true;
    }
    else if( a.nombre.size() > b.nombre.size() ){
      return false;
    }
    else{
      return (a.nombre>b.nombre);
    }
  }
};

int main(){
  priority_queue<Persona,vector<Persona>,Persona> pq;
  Persona p1,p2;
  p1.apellidos = "Ruiz";
  p1.nombre = "Jose Antonio";
  p2.apellidos = "Millan";
  p2.nombre = "Pepe";
  pq.push(p1);
  pq.push(p2);

  while(!pq.empty()){
    cout << pq.top().nombre << endl;
    pq.pop();
  }
  cout << endl;
}
