/*
Resuelve el problema anterior pero sobre una única lista pasada por referencia.
*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>

/**
@brief Invierte una lista
@param l: lista a la que vamos a alterarle el orden. SE MODIFICA
@return devuelve la lista por referencia en orden inverso
*/
void orden_inverso(list<T> &l){
  T aux;
  int tam = l.size()/2;
  int i = 0;
  typename list<T>::iterator iti;
  typename list<T>::iterator itf = l.end();

  --itf;
  for( iti = l.begin(); i < tam ; ++iti,--itf ){
    aux = *iti;
    *iti = *itf;
    *itf = aux;
    i++;
  }
}

int main(){
  list<int> l;
  list<int>::iterator it;

  l.push_back(2);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(1);
  l.push_back(5);
  l.push_back(3);

  cout << "La lista es: " << endl;
  for( it = l.begin(); it != l.end(); ++it ){
    cout << *it << endl;
  }

  orden_inverso(l);

  cout << "En orden inverso: " << endl;
  for( it = l.begin(); it != l.end(); ++it ){
    cout << *it << endl;
  }
}
