/*
Implementa la función intercalar(vector<T> &v, vector<pair<int, T> > pos)
que inserta el segundo elemento de cada par de pos en v en los lugares indicados por el primer
elemento de cada par de pos
*/

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos){
  int max = pos[0].first;

  for( auto it = pos.begin(); it != pos.end(); ++it ){
    if ( it->first > max ){
      max = it->first;
    }
  }
  bool aniadido;
  for( int i = 0; i < max+1; i++ ){
    aniadido = false;
    for( auto it = pos.begin(); it != pos.end() && !aniadido; ++it ){
      if( i == it->first ){
        v.push_back(it->second);
        aniadido = true;
      }
    }
    if(!aniadido){
      v.push_back(NULL);
    }
  }
}

int main(){
  vector<pair<int, int> > v1;
  vector<int> v2;

  v1.push_back(pair<int, int>(5,5));
  v1.push_back(pair<int, int>(2,2));
  v1.push_back(pair<int, int>(1,1));
  v1.push_back(pair<int, int>(7,7));

  intercalar(v2,v1);

  for( int i = 0; i < v1.size(); i++ ){
    cout << v1[i].first << v1[i].second << " ";
  }
  cout << endl;

  for( int i = 0; i < v2.size(); i++ ){
    cout << v2[i] << " ";
  }
  cout << endl;

}
