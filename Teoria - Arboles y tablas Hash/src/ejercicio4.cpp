/**
Supongamos que tenemos una funci ́on valor tal que dado un valor de tipo char (una letra del alfa-
beto) devuelve un valor entero asociado a dicho identificador. Supongamos tambien la existencia de
un a  ́ rbol de expresi ́on T cuyos nodos hoja son letras del alfabeto y cuyo s nodos interiores son los
caracteres *, +, -, /. Dise ̃nar una funci ́on que tome como par ́ametros un nodo y un a  ́ rbol binario y
devuelva el resultado entero de la calculoci ́on de la expresi ́on re presentada.
*/
#include <iostream>
#include "bintree.h"

using namespace std;

int valor(char a){
  return a;
}

template<typename T>
int calculo(const typename bintree<T>::node &n,const bintree<T> &A){
  char ident;

  ident = *n;
  switch(ident){
    case '+':
      return calculo(n.left(),A)+calculo(n.right(),A);
      break;
    case '-':
      return calculo(n.left(),A)-calculo(n.right(),A);
      break;
    case '*':
      return calculo(n.left(),A)*calculo(n.right(),A);
      break;
    case '/':
      return calculo(n.left(),A)/calculo(n.right(),A);
      break;
    default:
      return valor(ident);
      break;
  }
}

int main(){
  bintree<char> prueba('+');

  prueba.insert_left(prueba.root(), '+');
  prueba.insert_right(prueba.root(), '-');
  prueba.insert_left(prueba.root().left(), 'a');
  prueba.insert_right(prueba.root().left(), 'b');
  prueba.insert_left(prueba.root().right(), 'd');
  prueba.insert_right(prueba.root().right(), 'c');

  // Creamos el árbol:
  //        +
  //     /    \
  //    +      -
  //  /  \    / \
  // a    b  c  d

  int res = calculo(prueba.root(),prueba);

  cout << res << endl;
}
