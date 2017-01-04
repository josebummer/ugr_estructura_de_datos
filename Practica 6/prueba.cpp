#include <iostream>
#include <map>
#include <list>

using namespace std;

int main(){
  map<int,list<int> > m;
  // map<int,int> m;
  // m.insert(pair<int,int>(0,5));
  // m.insert(pair<int,int>(1,3));
  // m.insert(pair<int,int>(3,3));
  // m.insert(pair<int,int>(3,6));
  // m[0] = 1;
  // m[1] = 3;
  // m[2] = 3;
  // m[3] = 6;
  list<int> l;

  m[0].push_back(2);
  m[0].push_back(4);
  m[0].push_back(6);

  // for ( map<int,int>::iterator it = m.begin(); it != m.end(); ++it ){
  //   cout << it->first << " " << it->second << endl;
  // }
  for ( map<int,list<int> >::iterator it = m.begin(); it != m.end(); ++it ){
    cout << it->first << " --- ";
    l = it->second;
    for( list<int>::iterator it2 = l.begin(); it2 != l.end(); ++it2 ){
      cout << *it2 << " ";
    }
    cout << endl;
  }

  m[0].remove(2);
  m[0].remove(4);
  m[0].remove(6);
  if( m[0].empty() )
    m.erase(0);

  // cout << endl << endl;
  // for ( map<int,int>::iterator it = m.begin(); it != m.end(); ++it ){
  //   cout << it->first << " " << it->second << endl;
  // }
  for ( map<int,list<int> >::iterator it = m.begin(); it != m.end(); ++it ){
    cout << it->first << " --- ";
    l = it->second;
    for( list<int>::iterator it2 = l.begin(); it2 != l.end(); ++it2 ){
      cout << *it2 << " ";
    }
    cout << endl;
  }
}
