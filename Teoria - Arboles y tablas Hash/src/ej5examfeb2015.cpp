/**
Implementa una función que compruebe si un árbol binario es simétrico de otro.
*/
#include <iostream>
#include "bintree.h"
#include <string>

using namespace std;

///////////////////////// FORMA MENOS EFICIENTE ////////////////////////////////

template<typename T>
string RecorridoInoden(const bintree<T> &A, const typename bintree<T>::node &n){
  string resultado;
  if( !n.null() ){
    resultado += RecorridoInoden(A,n.left());
    resultado += to_string(*n);
    resultado += RecorridoInoden(A,n.right());
    return resultado;
  }
}

template<typename T>
bool simetricos(const bintree<T> &a, const bintree<T> &b){
  string as = RecorridoInoden(a,a.root());
  string bs = RecorridoInoden(b,b.root());

  if( as.size() != bs.size() )
    return false;

  int i, j = as.size()-1;
  for( i = 0; i < as.size(); i++,j-- ){
    if( as[i] != bs[j] )
      return false;
  }
  return true;

}
////////////////////////////////////////////////////////////////////////////////

///////////////////////// FOMRMA MAS EFICIENTE//////////////////////////////////

bool auxsim( const bintree<T> &a, const typename bintree<T>::node &na, const bintree<T> &b, const typename bintree<T>::node &nb ){
  if( !na.null() && !nb.null() ){
    if( *na == *nb ){
      return (auxsim(a,na.left(),b,nb.right()) && auxsim(a,na.right(),b,nb.left()));
    }
  }
  else if( na.null() && nb.null() ){
    return true;
  }
  return false;
}

template<typename T>
bool simetricosef(const bintree<T> &a, const bintree<T> &b){
  return auxsim(a,a.root(),b,b.root());

}

////////////////////////////////////////////////////////////////////////////////
int main(){
  bintree<int> prueba(5);

  prueba.insert_left(prueba.root(), 3);
  prueba.insert_left(prueba.root().left(), 1);
  prueba.insert_right(prueba.root().left(), 4);
  prueba.insert_right(prueba.root(), 8);
  prueba.insert_left(prueba.root().right(), 6);
  prueba.insert_right(prueba.root().right(), 9);
  prueba.insert_right(prueba.root().right().left(), 7);

  //      Arbol:
  //        5
  //     /    \
  //    3      8
  //  /  \    / \
  // 1    4  6   9
  //          \
  //          7

  bintree<int> prueba2(5);

  prueba2.insert_left(prueba2.root(), 8);
  prueba2.insert_left(prueba2.root().left(), 9);
  prueba2.insert_right(prueba2.root().left(), 6);
  prueba2.insert_right(prueba2.root(), 3);
  prueba2.insert_left(prueba2.root().right(), 4);
  prueba2.insert_right(prueba2.root().right(), 1);
  prueba2.insert_left(prueba2.root().left().right(), 7);

  //      Arbol:
  //        5
  //     /    \
  //    8      3
  //  /  \    / \
  // 9    6  4   1
  //     /
  //    7

  bool sim = simetricos(prueba,prueba2);
  bool sime = simetricosef(prueba,prueba2);

  if(sime){
    cout << "Los arboles son simetricos." << endl;
  }
  else{
    cout << "Los arboles no son simetricos" << endl;
  }
}
