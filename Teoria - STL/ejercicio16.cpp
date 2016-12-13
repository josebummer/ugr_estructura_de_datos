/*
Implementa la clase vector dinámico usando como representación el tipo list. ¿Qué orden de eficiencia
tiene cada operación?
*/

#include <iostream>
#include <list>
#include <cassert>

using namespace std;

template<typename T>
class vector_dinamico{
private:
  list<T> l;
public:
  typedef typename list<T>::iterator iterator;

  vector_dinamico(){}

  iterator begin(){
    return l.begin();
  }

  iterator end(){
    return l.end();
  }

  int size(){
    return l.size();
  }
  bool empty(){
    return l.empty();
  }
  T& operator[](int pos) {
    iterator it;
    int i = 0;
    for( it = l.begin(); it != l.end(); ++it ){
      if ( i == pos ){
        return *it;
      }
      i++;
    }
    assert(it == l.end());
  }
  const T& operator[](int pos) const{
    iterator it;
    int i = 0;
    for( it = l.begin(); it != l.end(); ++it ){
      if ( i == pos ){
        return *it;
      }
      i++;
    }
    assert(it == l.end());
  }
  T front(){
    return l.front();
  }
  T back(){
    return l.back();
  }
  void push_back(const T &elem){
    l.push_back(elem);
  }
  void pop_back(){
    l.pop_back();
  }
  void insert(vector_dinamico::iterator it , T elem ){
    l.insert(it,elem);
  }
  void erase(vector_dinamico::iterator it){
    l.erase(it);
  }
  void clear(){
    l.clear();
  }
};

int main(){
  vector_dinamico<int> v;

  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
  v.push_back(8);
  v.push_back(9);
  v.push_back(5);

  for( int i = 0; i < v.size(); i++ ){
    cout << v[i] << " " << endl;
  }
  cout << endl;
  v.pop_back();

  for( int i = 0; i < v.size(); i++ ){
    cout << v[i] << " " << endl;
  }
  cout << endl;

}
