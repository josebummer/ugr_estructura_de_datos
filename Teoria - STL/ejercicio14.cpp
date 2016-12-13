/*
Una variante del vector disperso es aquella en la que se puede definir cual es el valor nulo. Modifica
la clase anterior de forma que se pueda definir cual es el valor nulo al crear un objeto. Implementa
también cambiar_nulo(const T &n)
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
class vdisperso {
public:
  vdisperso(const vector<T> &v, T p_vnulo){
    n = 0;
    vnulo = p_vnulo;

    for( int i = 0; i < v.size(); i++ ){
      if( v[i] != vnulo ){
        coefs.push_back(pair<int, T>(i,v[i]));
        n++;
      }
    }
  }
  void asignar_coeficiente(int i, const T &x){
    typename list< pair<int, T> >::iterator it;
    bool asignado = false;

    for( it = coefs.begin(); it != coefs.end() && !asignado; ++it ){
      if( i == *it->first ){
        *it->second = x;
        asignado = true;
      }
    }
  }
  vector<T> convertir() const{
    typename list< pair<int, T> >::const_iterator it = coefs.begin();
    int i = 0;
    vector<T> res;

    while( it != coefs.end() ){
      if( i == it->first ){
        res.push_back(it->second);
        ++it;
      }
      else{
        res.push_back(vnulo);
      }
      i++;
    }
    return res;
  }
  void mostrarLista(){
    typename list< pair<int, T> >::iterator it;
    for( it = coefs.begin(); it != coefs.end(); ++it){
      cout << it->second << " ";
    }
    cout << endl;
  }
private:
  list< pair<int, T> > coefs;
  int n;
  T vnulo;
};

int main(){
  vector<int> v,v2;

  v.push_back(9);
  v.push_back(5);
  v.push_back(2);
  v.push_back(9);
  v.push_back(1);
  v.push_back(7);
  v.push_back(4);

  vdisperso<int> l(v,9);

  v2 = l.convertir();

  for( int i = 0; i < v.size(); i++ ){
    cout << v[i] << " ";
  }
  cout << endl;

  for( int i = 0; i < v2.size(); i++ ){
    cout << v2[i] << " ";
  }
  cout << endl;

  l.mostrarLista();
}
