/*
Implementa una función list<T> mezclar(const list<T> &l1, const list<T> &l2)
que dadas dos listas ordenadas l1 y l2 devuelva una lista ordenada mezclando las dos listas.
*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>

/**
@brief Mezcla dos listas ordenadas en una sola lista. ELIMINA REPETIDOS
@param l1: lista 1
@param l2: lista 2
@pre las dos listas que se pasan como parametro deben estar ordenadas
@return una lista con la mezcla de las dos listas ordenadas. SIN REPETIDOS
*/
list<T> mezclar(const list<T> &l1, const list<T> &l2){
  list<T> res;
  typename list<T>::const_iterator it = l1.begin();
  typename list<T>::const_iterator it2 = l2.begin();

  while( it != l1.end() && it2 != l2.end() ){
    if( *it < *it2 ){
      res.push_back(*it);
      ++it;
    }
    else if( *it2 < *it ){
      res.push_back(*it2);
      ++it2;
    }
    else{
      res.push_back(*it);
      ++it;
      ++it2;
    }
  }
  if( it == l1.end() &&  it2 != l2.end()){
    while ( it2 != l2.end() ){
      res.push_back(*it2);
      it2++;
    }
  }
  else if( it != l1.end() &&  it2 == l2.end() ){
    while ( it != l1.end() ){
      res.push_back(*it);
      ++it;
    }
  }
  return res;
}

int main(){
  list<int> l1,l2;
  list<int> mezcla;
  list<int>::iterator it;

  l1.push_back(1);
  l1.push_back(5);
  l1.push_back(8);
  l1.push_back(9);
  l1.push_back(12);

  l2.push_back(2);
  l2.push_back(5);
  l2.push_back(9);
  l2.push_back(10);

  mezcla = mezclar(l1,l2);

  cout << "La lista1 es: " << endl;
  cout << "< ";
  for( it = l1.begin(); it != l1.end(); ++it ){
    cout << *it << " ";
  }
  cout << ">" << endl;

  cout << "La lista2 es: " << endl;
  cout << "< ";
  for( it = l2.begin(); it != l2.end(); ++it ){
    cout << *it << " ";
  }
  cout << ">" << endl;

  cout << "La mezcla es: " << endl;
  cout << "< ";
  for( it = mezcla.begin(); it != mezcla.end(); ++it ){
    cout << *it << " ";
  }
  cout << ">" << endl;

}
