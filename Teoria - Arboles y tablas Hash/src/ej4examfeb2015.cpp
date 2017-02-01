
/**
Tenemos un contenedor de pares de elementos, {clave, vector<int>} definida
como:
template <typename T>
class contenedor{
private:
unordered_map<T, vector<int> > datos;
.............
.............
}
Implementa un iterador que itere sobre los elementos que cumplan la propiedad de
que la suma de los elementos del vector<int> sea un número impar. Han de
implementarse (aparte de las de la clase iteradora) las funciones begin() y end().
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool esImpar(int i) {
  return (i%2 != 0);
}
int suma(const vector<int> &v) {
  int sum = 0;
  for( int i = 0; i < v.size(); i++){
    sum += v[i];
  }
  return sum;
}

template <typename T>
class contenedor{
private:
  unordered_map<T, vector<int> > datos;
public:
  contenedor(){
  }
  void insertar(const T &clave, const vector<int> &v){
    datos[clave] = v;
  }

  class iterator{
  private:
    typename unordered_map<T, vector<int> >::iterator it;
    unordered_map<T, vector<int> > *elmapa;
  public:
    iterator(){}

    iterator( const typename contenedor<T>::iterator &otro ){
      this->it = otro.it;
    }
    typename contenedor<T>::iterator & operator++(){
      while( (it != elmapa->end()) ){
        ++it;
        if( it != elmapa->end() && esImpar(suma(it->second)) )
          return *this;
      }
      return *this;
    }
    typename contenedor<T>::iterator & operator--(){
      while( !esImpar(suma(it->second)) && it != elmapa->begin() ){
        --it;
      }
      return *this;
    }
    typename contenedor<T>::iterator & operator=( const typename contenedor<T>::iterator &otro){
      if( this != &otro )
        elmapa = otro.elmapa;
        this->it = otro.it;
      return this;
    }
    bool operator==( const typename contenedor<T>::iterator &otro ) const{
      return ( elmapa == otro.elmapa && it == otro.it );
    }
    bool operator!=( const typename contenedor<T>::iterator &otro ) const{
      return ( elmapa != otro.elmapa || it != otro.it );
    }
    pair<T,vector<int> > operator*()const{
      pair<T,vector<int> > res;
      res.first = it->first;
      res.second = it->second;
      return res;
    }
    friend class contenedor<T>;
  };
  typename contenedor<T>::iterator begin(){
    typename unordered_map<T, vector<int> >::iterator it = datos.begin();
    typename contenedor<T>::iterator res;
    res.elmapa = &datos;
    while( it != datos.end() ){
      if( esImpar(suma(it->second)) ){
        res.it = it;
        return res;
      }
      ++it;
    }
    res.it = datos.end();
    return res;
  }
  typename contenedor<T>::iterator end(){
    typename contenedor<T>::iterator res;
    res.elmapa = &datos;
    res.it = datos.end();
    return res;
  }
};

int main(){
  contenedor<int> prueba;
  vector<int> v;
  vector<int> v2;

  for ( int i = 1 ; i <= 10; i++){
    v.push_back(i);
  }
  for ( int i = 2 ; i <= 10; i++){
    v2.push_back(i);
  }

  prueba.insertar(6,v);
  prueba.insertar(2,v);
  prueba.insertar(1,v2);
  prueba.insertar(8,v);
  prueba.insertar(4,v);
  prueba.insertar(9,v);

  for( typename contenedor<int>::iterator it2 = prueba.begin(); it2 != prueba.end(); ++it2 ){
        cout << (*it2).first << endl;
  }

}
