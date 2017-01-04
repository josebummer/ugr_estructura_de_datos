#include <iostream>
#include <string>
#include <set>

using namespace std;
typedef int IDmut;

int main(){
  set<IDmut,less<int> > res;

  res.insert(6);
  res.insert(4);
  res.insert(14);

  for( set<IDmut,less<string> >::iterator it = res.begin(); it != res.end(); ++it ){
    cout << *it << " ";
  }
  cout << endl;
}
