#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  multimap<int,string> m;
  multimap<int,string>::iterator it;

  m.insert(pair<int,string>(0,"hola"));
  m.insert(pair<int,string>(0,"pepe"));

  it = m.find(0);
it = m.find(0); 
  cout << it->first << " " << it->second << endl;

  // for ( multimap<int,string>::iterator it = m.begin(); it != m.end(); ++it ){
  //   cout << it->first << " " << it->second << endl;
  // }
}
