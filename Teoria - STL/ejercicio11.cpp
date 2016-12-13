/*
Implementa una función bool contenida(const list<T> &l1, const list<T> &l2)
a la que se le pasen dos listas y compruebe si la lista l1 está contenida en l2 (si los elementos apa-
recen en la otra y en el mismo orden).
*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>

/**
@brief Comprueba si una lista esta contenida dentro de otra lista (conservando el orden)
@pre las dos listas deben tener elementos
@param l1: lista donde se comprobara si contiene a la otra lista
@param l2: lista que se comprobara si su contenido esta en la otra lista
@return devuelve true si l2 esta contenida en l1 y false en caso contrario
*/
bool contenida(const list<T> &l1, const list<T> &l2){
  typename list<T>::const_iterator it1 = l1.begin();
  typename list<T>::const_iterator it2 = l2.begin();

  while( it1 != l1.end() ){
    if( *it1 == *it2 ){
      while ( it2 != l2.end() && *it1 == *it2 ){
        ++it1;
        ++it2;
      }
      if( it2 == l2.end() ){
        return true;
      }
      else{
        it2 = l2.begin();
      }
    }
    ++it1;
  }
  return false;
}

int main(){
  list<int> l1,l2;
  list<int>::iterator it1;

  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);
  l1.push_back(5);
  l1.push_back(6);
  l1.push_back(7);
  l1.push_back(8);

  l2.push_back(4);
  l2.push_back(5);
  l2.push_back(6);
  l2.push_back(7);
  l2.push_back(8);

  cout << "La lista 1 es:" << endl;
  for( it1 = l1.begin(); it1 != l1.end(); ++it1 ){
    cout << *it1 << " ";
  }
  cout << endl;

  cout << "La lista 2 es:" << endl;
  for( it1 = l2.begin(); it1 != l2.end(); ++it1 ){
    cout << *it1 << " ";
  }
  cout << endl;

  if(contenida(l1,l2)){
    cout << "La lista 2 esta contenida en la lista 1." << endl;
  }
  else{
    cout << "La lista 2 no esta contenida en la lista 1." << endl;
  }
}
