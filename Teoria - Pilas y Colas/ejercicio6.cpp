/*
Dada una matriz que representa un laberinto, construye una función que determine si se puede llegar
desde la entrada hasta la salida. Esta matriz tendrá una ’E’ en la entrada, una ’S’ en la salida, un ’0’
en las casillas por las que se pueda pasar y un ’1’ en las que no. No se puede ir en diagonal.
*/

#include <iostream>
#include <vector>
#include <stack>
#define FC 10

using namespace std;

typedef vector<vector<char> > matrizchar;                    //Definimos un tipo de dato matriz que es un vector de vectores
typedef vector<vector<bool> > matrizbool;

/**
@brief Dado una matriz que representa un laberinto, encuentra si existe un camino posible
@param m: Matriz que contiene el laberinto
@pre Todas las filas deben tener el mismo numero de columnas
@pre El camino ha seguir debe estar representado por el caracter '0'
@pre Las posiciones por donde no se puede pasar se representan con el caracter '1'
@pre La entrada o inicio del laberinto se representa con el caracter 'E'
@pre La salida del laberinto se representa con el caracter 'S'
@return Devuelve true si encuentra el camino desde E hasta S y false en caso contrario
*/
bool caminoCorrecto( const matrizchar& m  ){
  matrizbool pisadas(m.size(),vector<bool>(m[0].size(),false));  //Creamos un vector del mismo tamaño para representar las posiciones pisadas
  int i, j;                                       //Indican la posicion en la que nos encontramos
  bool encontrado = false;                        //La usaremos para encontrar la 'E' en el laberinto
  for( int k = 0; k < m.size() && !encontrado; k++ ){
    for ( int l = 0; l < m[k].size() && !encontrado; l++ ){         //Buscamos en todo el laberinto la 'E' para comenzar
      if( m[k][l] == 'E' ){
        i = k;                                                      //Una vez la encontremos se la asignamos a i y j para comenzar
        j = l;
        encontrado = true;
      }
    }
  }
  stack<int> posiciones;                            //Creamos la pila donde vamos a ir guardando las posiciones
  int k , l;                                        //Representaran las posiciones de la casilla que estamos consultando
  for(  k = i-1; k <=i+1; k++){
    if( k >=0 && k<m.size() ){         //Revisamos las casillas de la cercania hacia donde nos encontramos obviando si se salen de la matriz
      for( l = j-1; l<=j+1; l++){
        if( (j>=0 && j<m[k].size()) && ((i!=k && j==l) || (i==k && j!=l))){   //Tenemos en cuenta tanto que no se sale de la matriz como que no son diagonales
          if( m[k][l] == 'S' ){                       //Comprobamos si hemos encontrado la salida
            return true;                              //En caso afirmativo devolvemos true y hemos terminado
          }
          else if( m[k][l] == '0' && !pisadas[k][l] ){      //Si no es la salida comprobamos si es '0' y no esta pisada
            posiciones.push(j);                             //En caso afirmativo guardamos la posicion donde nos encontramos en la pila
            posiciones.push(i);
            pisadas[i][j] = true;                           //Ponemos la casilla en la que nos encontramos como pisada
            i = k;                                          //Asignamos la siguiente casilla para colocarnos en ella
            j = l;
            k = i-2;                                        //Actualizamos el valor de k
            break;                                          //Salimos del bucle para empezar a buscar a partir de la siguiente posicion nueva
          }
        }
      }
      if( k == i+1 && l == j+2 ){                   //En el caso de que hayamos mirado todas las posiciones posibles respecto de la casilla
        if( posiciones.empty() ){                   //Comprobamos si la pila esta vacia
          return false;                             //Si esta vacia significa que no existe camino posible
        }
        else{                                       //En el caso de que tenga elementos
          pisadas[i][j] = true;                     //Marcamos la casilla actual como pisada
          i = posiciones.top();                     //Cojemos la posicion anterior almacenada en la pila
          posiciones.pop();
          j = posiciones.top();
          posiciones.pop();
          k = i-2;                                  //Actualizamos 'k' para seguir comprobando caminos posibles
        }
      }
    }
  }
}

int main(){
  matrizchar juego(FC,vector<char>(FC,'1'));

  juego[2][4] = 'E';
  juego[9][9] = 'S';
  juego[1][7] = '0';
  juego[2][5] = '0';
  juego[2][6] = '0';
  juego[2][7] = '0';
  juego[2][8] = '0';
  juego[2][9] = '0';
  juego[3][9] = '0';
  //juego[4][9] = '0';
  juego[5][9] = '0';
  juego[6][9] = '0';
  juego[7][9] = '0';
  juego[8][9] = '0';
  juego[3][7] = '0';
  juego[4][7] = '0';
  juego[5][7] = '0';
  juego[6][7] = '0';
  juego[6][8] = '0';
  /*
  0 1 2 3 4 5 6 7 8 9


  1 1 1 1 1 1 1 1 1 1       0
  1 1 1 1 1 1 1 0 1 1       1
  1 1 1 1 E 0 0 0 0 0       2
  1 1 1 1 1 1 1 0 1 0       3
  1 1 1 1 1 1 1 0 1 1       4
  1 1 1 1 1 1 1 0 1 0       5
  1 1 1 1 1 1 1 0 0 0       6
  1 1 1 1 1 1 1 1 1 0       7
  1 1 1 1 1 1 1 1 1 0       8
  1 1 1 1 1 1 1 1 1 S       9
  */

  if( caminoCorrecto( juego ) ){
    cout << "Tenemos camino hasta el final." << endl;
  }
  else{
    cout << "NOO existe camino hasta el final." << endl;
  }
}
