/*
Implementa una función que dada una lista l devuelva una lista que tenga los elementos de l pero en
orden inverso.
*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>

/**
@brief Invierte una lista
@param l: lista a la que vamos a alterarle el orden
@return devuelve una nueva lista con orden inverso a la lista pasada por parametros
*/
list<T> orden_inverso(const list<T> &l){
  list<T> res;
  typename list<T>::const_iterator it;

  for( it = l.begin(); it != l.end(); ++it ){
    res.push_front(*it);
  }
  return res;
}

int main(){
  list<int> l;
  list<int> invl;
  list<int>::iterator it;

  l.push_back(2);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(5);
  l.push_back(3);

  invl = orden_inverso(l);

  cout << "La lista es: " << endl;
  for( it = l.begin(); it != l.end(); ++it ){
    cout << *it << endl;
  }
  cout << "En orden inverso es: " << endl;
  for( it = invl.begin(); it != invl.end(); ++it ){
    cout << *it << endl;
  }
}
