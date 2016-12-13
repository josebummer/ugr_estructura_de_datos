/*
Implementa una función elimina_duplicados(list<T> &l) que elimine los elementos du-
plicados (sin ordenar previamente la lista).
*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>

/**
@brief Elimina duplicados de una lista
@param l: lista ha la que le eliminaremos los duplicados. SE MODIFICA
@return devuelve la propia lista por referencia con los cambios realizados
*/
void elimina_duplicados(list<T> &l){
  typename list<T>::iterator it, c;

  for( it = l.begin(); it != l.end(); ++it ){
    c = it;
    ++c;
    while( c != l.end() ){
      if( *c == *it ){
        c = l.erase(c);
      }
      else{
        ++c;
      }
    }
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
  l.push_back(2);

  elimina_duplicados(l);

  for( it = l.begin(); it != l.end(); ++it ){
    cout << *it << endl;
  }
}
