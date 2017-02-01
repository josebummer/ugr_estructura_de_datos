/*
Implementa una función bool sumaIgual(const list<list<int> > &L) que
devuelve true si todas las sumas por filas y por columnas da el mismo resultado (se
asume que todas las listas tienen igual longitud). Por ejemplo, en la siguiente lista si se
suma cada fila y cada columna siempre se obtiene 3

L=< <0,1,1,1>,
    <2,1,0,0>,
    <1,0,2,0>,
    <0,1,0,2> >
*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int maximo(const list<int> &l){
  if( l.size() == 0 )
    return 0;
  int sum = 0;
  for( typename list<int>::const_iterator it = l.begin(); it != l.end(); ++it ){
    sum += *it;
  }
  return sum;
}

bool sumaIgual(const list<list<int> > &L){
  if( L.size() == 0 )
    return false;

  vector<int> sumas (L.front().size(),0);
  int i;
  int max = maximo(L.front());
  for( typename list<list<int> >::const_iterator it = L.begin(); it != L.end(); ++it ){
    int sum = 0;
    i = 0;
    for( typename list<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2,i++ ){
      sum+=*it2;
      sumas[i] += *it2;
    }
    if( sum != max )
      return false;
  }

  for( i = 0; i < sumas.size(); i++ ){
    if( sumas[i] != max )
      return false;
  }

  return true;
}

int main(){
  list<list<int> > l;

  l.push_back(list<int>{0,1,1,1});
  l.push_back(list<int>{2,1,0,0});
  l.push_back(list<int>{1,0,2,0});
  l.push_back(list<int>{0,1,0,2});

  bool igual = sumaIgual(l);

  if(igual){
    cout << "La suma de todas las filas y columnas son iguales." << endl;
  }
  else{
    cout << "No coinciden las sumas de todas las filas y columnas" << endl;
  }
}
