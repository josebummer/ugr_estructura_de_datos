
/**
 * @file Nmer.h
 * @brief TDA Nmer
 *   Representa un conjunto de Nmer subsecuencias de tamaño 1 hasta N que se pueden obtener a partir de una cadena de ADN
 * @author Jose Antonio Ruiz Millan
 */
#ifndef __NMER_H
#define __NMER_H

#include "ktree.h"
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class OrdenCre{
public:
  bool operator()(const pair<string,int> &p1 , const pair<string,int> &p2){
    return (p1.second <= p2.second);
  }
};

class OrdenDecre{
public:
  bool operator()(const pair<string,int> &p1 , const pair<string,int> &p2){
    return (p1.second >= p2.second);
  }
};

class Nmer {
public:
  typedef unsigned int size_type;

  /** @brief Constructor primitivo .
      Crea un Nmer de longitud maxima 0, con el valor ('-',0) en la raíz
  */
  Nmer();

  /** @brief Constructor de copia .
      Crea un Nmer que es la copia del que pasamos por argumento.
      @param otro: Nmer a copiar;
  */
  Nmer(const Nmer &otro);

  /** @brief lectura fichero serializado
   * @param nombre_fichero fichero serializado con extension .srl
   *
   * Genera a partir del fichero el ktree que contiene todos los kmers asociados a una cadena de ADN
   *
   * La cadena original viene descrita en el fichero serializado
   */
  bool loadSerialized(const string & nombre_fichero);


  /** @brief Imprime los Nmers
   * @todo Debemos de implementar este método de forma que nos garantizemos que se imprimen todos los Nmers.
   */
   void list_Nmer() const;


  /** @brief Máxima longitud de los Nmers almacenados
   */
   unsigned int length()const;


  /** @brief Número de Nmers almacenados
   */
   size_type size() const;

   /**
  @brief Operador de asignacion
  @return devuelve la referencia a Nmer
   */
   Nmer & operator=(const Nmer & a);

   /**
   @brief Busca la cadena adn en al arbol
   @param adn: cadena ha buscar en el arbol
   @return devuelve true si la cadena se encuentra en el arbol y false en caso contrario
   */
   bool containsString(const string adn) const;

   /**
   @brief Saca todas las cadenas de l tamaño en la cadena adn y llama a insertar_cadena
   @param l: tamaño de cada palabra
   @param adn: string con la cadena completa
   */
   void sequenceADN(unsigned int l, const string & adn);

   /**
    @brief Busca la secuencia que se pasa como adn y devuelve un Nmer desde ese adn para abajo.
    @param adn: string que contiene el la secuencia ha buscar
    @return Un Nmer asociado a un prefijo.
   */
   Nmer Prefix(const string &adn);

   /**
   @brief Crea un nuevo Nmer que tiene la suma de cada nodo actual con el nudo del arbol
   * reference
   @param reference: Nmer que usaremos para sumar con el Nmer actual
   @return devuelve un Nmer donde para cada nodo se computa la suma de las frecuencias en *this y en referencia
   */
  Nmer Union(const Nmer &reference) const;

  /*
  @brief Crea un pair que contiene el conjunto de subcadenas (no prefijo) que aparecen un número de veces menor o igual a
  * threshold veces en el Nmer.
  @param threshold: Entero que el numero de aparaciones que buscamos
  @return un set de pair donde la cadena se almacenará en el primer campo del par, mientras que en el segundo
  * dispondremos de la frecuencia de aparición de la cadena
  */
  set <pair<string,int> ,OrdenCre >rareNmer(int threshold) const;

  /*
  @brief Crea un pair que contiene el conjunto de subcadenas (no prefijo) que aparecen un número de veces mayor a
  * threshold veces en el Nmer.
  @param threshold: Entero que el numero de aparaciones que buscamos
  @return un set de pair donde la cadena se almacenará en el primer campo del par, mientras que en el segundo
  * dispondremos de la frecuencia de aparición de la cadena
  */
  set <pair<string,int> ,OrdenDecre > commonNmer(int threshold) const;

  /**
  @brief Busca los Nmer que tienen una longitud de 'l' y los devuelve
  @param l: longitud de los Nmer ha buscar
  @return Develve los Nmer de longitud 'l' con sus frecuencias
  */
  set<pair<string,int> ,OrdenCre > level(int l) const;

  /**
  @brief Calcula la distancia que hay entre 2 Nmer
  @param Nmer: Nmer a compara con el this
  @return Devuelve la distancia entre ellos.
  */
  float Distance(const Nmer &otro) const;

  /**
  @brief Comprueba si todos los nodos de this estan representados en reference
  @param reference: Nmer a comparar
  @return Devuelve true si todos los nodos de this estan representados en reference,
  * fals en caso contrario.
  */
  bool included(const Nmer &reference) const;

private:
  ktree<pair<char,int>,4> el_Nmer; // subsecuencias
  unsigned int max_long; // Mayor longitud de la cadena representada, esto es, el nivel máximo del árbol

  /** @brief Functor para convertir un string en un pair<char,int>
   * se utiliza en loadSerialized
   */
  class String2Base {
   public:
    pair<char,int> operator()( const string & cad) {
	    pair<char,int> salida;
	    salida.first = cad[0];
	    salida.second = std::stoi(cad.substr(1));
	    return salida;
    }
  };

   /** @brief Functor para convertir un pair<char,int> en un string
    * Necesario para serializar un Nmer.
   */
  class Base2String {
   public:
     string operator()( const pair<char,int> & x) {
       string salida = string(1,x.first) + " " +std::to_string(x.second);
       return salida;
     }
  };

  /**
  @brief @brief inserta una cadena en el arbol de Nmer
  @param cadena: string ha insertar en el arbol.
  */
  void insertar_cadena(const string & cadena);

  /**
  @brief Metodo que nos ayudara para completar el funcionamiento de list_Nmer()
  @param n: nodo desde donde se empieza a recorrer el arbol
  @param elem: nos permitira llevar la suma de cada una de las cadenas
  */
  void recorrer_mostrar(typename ktree<pair<char,int>,4>::const_node n,string &elem) const;

  /**
  @brief Nos ayudara para saber donde va posicionado cada hijo en cada nodo
  @param elem: elemento que queremos insertar al nodo
  @return Devuelve la posicion donde debe ir posicionado el elemento 'elem'
  */
  unsigned getPosicion(char elem) const;

  /**
  @brief Nos ayudara para guardar en un set de pair las distintas cadenas de un Nmer
  @param n: nodo desde donde empezaremos a recorrer.
  @param elem: string donde iremos almacenando las cadenas
  @param s: set donde almacenaremos las cadenas con sus frecuencias // SE MODIFICA Y SE DEVUELVE.
  @param t: parametro que nos permitira controlar hasta que frecuencia queremos llegar o desde cual empezar
  @param cre: true si queremos en resultado con la frecuencia ascendente y false para la frecuencia descendente
  */
  void recorrerGuardar(typename ktree<pair<char,int>,4>::const_node n,string &elem, set<pair<string,int> > &s, int t, bool cre) const;

};

#endif
