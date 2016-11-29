/*
Implementa una función insertar(Q, pos, x) que inserte un elemento en una cola Q en la posición pos.
La cola debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)
*/

//SE PUEDE HACER CON UNA COLA ROTANDO LOS DATOS COJIENDO EL FRONT Y HACIENDO PUSH SOBRE LA MISMA PILA
//PERO NO MEJORA EN EFICIENCIA


#include <iostream>
#include <queue>

using namespace std;

template<typename T>

/**
@brief Inserta un elemento en una posicion determinada de una cola
@param q: cola a la que se le va a insertar el elemento
@param pos: posicion donde se insertara el nuevo elemento
@param x: elemento a insertar en la cola
*/
void insertar( queue<T> & q , int pos , T x ){
  if( pos >=0 && pos <= q.size() ){                           //Comprobamos si se puede insertar el elemento
    queue<T> aux;                                             //Creamos una cola auxiliar donde guardaremos los elementos mas 'pos'
    int i = 0;
    while(!q.empty()){                                        //Guardamos los elementos en la cola auxiliar
      if( i == pos ){                                         //Si la posicion en la que nos encontramos es 'pos', insertamos 'x'
        aux.push(x);
      }
      else{                                                   //En caso contrario
        aux.push(q.front());                                  //Insertamos el elemento de la cola 'q'
        q.pop();
      }
      i++;
    }
    swap(aux,q);                                              //Intercambiamos los contenido de las colas
  }
}

int main(){
  queue<int> q;

  for( int i = 1; i < 10; i++ ){
    q.push(i);
  }
  insertar(q,4,3);
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
