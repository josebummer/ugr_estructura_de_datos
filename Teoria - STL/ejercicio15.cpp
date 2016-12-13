/*
Una forma eficiente de guardar secuencias de valores iguales consiste en guardar cada uno de los
valores seguido del número de veces que aparece en la secuencia. Por ejemplo,
<1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5>
< (1,3), (2,6), (7,5), (12,1), (1,2), (5,2) >
Implementa las funciones:
list<pair<T, int> > comprimir(const list<T> &l)
list<T> descomprimir(const list<pair<T, int> > &lc)
que permitan convertir entre ambas representaciones.
*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>
list<pair<T, int> > comprimir(const list<T> &l){
  typename list<T>::const_iterator it = l.begin();
  T elem = *it;
  int c = 0;
  list<pair<T, int> > res;

  while( it != l.end() ){
    if( *it == elem ){
      c++;
    }
    else{
      res.push_back(pair<T, int>(elem,c));
      elem = *it;
      c = 1;
    }
    ++it;
  }
  res.push_back(pair<T, int>(elem,c));

  return res;
}

template<typename T>
list<T> descomprimir(const list<pair<T, int> > &lc){
  typename list<pair<T, int> >::const_iterator it;
  list<T> res;

  for( it = lc.begin(); it != lc.end(); ++it ){
    for( int i = 0; i < it->second; i++ ){
      res.push_back(it->first);
    }
  }
  return res;
}

int main(){
  list<int> des;
  list<int>::iterator it2;
  list< pair<int,int> > com;
  list< pair<int,int> >::iterator it1;
//<1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5>
  des.push_back(1);
  des.push_back(1);
  des.push_back(1);
  des.push_back(2);
  des.push_back(2);
  des.push_back(2);
  des.push_back(2);
  des.push_back(2);
  des.push_back(2);
  des.push_back(7);
  des.push_back(7);
  des.push_back(7);
  des.push_back(7);
  des.push_back(7);
  des.push_back(12);
  des.push_back(1);
  des.push_back(1);
  des.push_back(5);
  des.push_back(5);

  com = comprimir(des);

  for( it1 = com.begin(); it1 != com.end(); ++it1){
    cout << "(" << it1->first << "," << it1->second << "), ";
  }
  cout << endl;
  des.clear();

  des = descomprimir(com);

  for( it2 = des.begin(); it2 != des.end(); ++it2){
    cout << *it2 << " ";
  }
  cout << endl;

}
