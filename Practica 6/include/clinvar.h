/*
Creado por: Jose Antonio Ruiz.

Practica 6 ED :
Universidad de Granada
*/

#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <list>
#include "enfermedad.h"
#include "mutacion.h"

using namespace std;

typedef string IDgen;
typedef string IDmut;
typedef string IDenf;

/**
@brief Funtor que utilizaremos para ordenar por probabilidad
*/
class ProbMutaciones{
public:
	bool operator()(const mutacion & m1, const mutacion & m2){
		float prob1 = 1.0-m1.getCaf()[0];
		float prob2 = 1.0-m2.getCaf()[0];

		return (prob1 >= prob2);
	}
};

class clinvar{
public:

	/* @brief iterador sobre enfermedades */
  // Nos vale utilizar el iterador del map
  typedef map<IDenf, enfermedad>::iterator enfermedad_iterator;

  //Clases de iteradores. Atributos y métodos definidos abajo.
	//@todo Implementa las clases de iteradores.
	class iterator;
	class gen_iterator;

	clinvar(){}

  /**
  @brief Se encarga de leer los elementos de un fichero dado por el argumento nombreDB, e insertar toda la información en ClinVar.
  @param nombreDB: Nombre del fichero donde se almacenan los datos
  */
  void load (string nombreDB);

  /**
  @brief Este método se encarga de insertar una nueva mutación en ClinVar. Esto implica actualizar todas las estructuras
  * necesarias para mantener la coherencia interna de la representación propuesta.
  @param x: mutacion ha insertar en ClinVar
  */
  void insert (const mutacion & x);

  /**
  @brief En este caso, se trata de borrar una mutación de la base de datos dado su ID.
  * No sólo borra la mutación del repositorio principal de datos sino que además se encarga de borrar toda referencia
  * a dicho elemento dentro de él.
  * En el caso de que una enfermedad estuviese asociada únicamente a la mutación que está siendo eliminada, esta
  * enfermedada también debe eliminarse de ClinVar.
  @param ID: ID de la mutacion ha eliminarse
  @return Devuelve verdadero si el elemento ha sido borrado correctamente, falso en caso contrario.
  */
  bool erase (IDmut ID);

  /**
  @brief Busca la mutación con identificador ID dentro de ClinVar
  @param ID: ID de la mutacion ha buscar
  @return El iterador a la mutacion, en caso de no existir, devuelve end()
  */
  clinvar::iterator find_Mut (IDmut ID);

  /**
  @brief Busca la enfermedad con identificador ID dentro de ClinVar
  @param ID: ID de la enfermedad ha buscar
  @return iterador que apunta a la enfermadad, si no lo encuentra devuelve end()
  */
  clinvar::enfermedad_iterator find_Enf(IDenf ID);

  /**
  @brief Busca todas las enfermedades asociadas a una mutación en la base de datos clinvar.
  @param mut: mutacion ha buscar para encontrar sus enfermedades asociadas
  @return un vector con todas las enfermedades asociadas a una mutación
  */
  vector<enfermedad> getEnfermedades(mutacion & mut);

  /**
  @brief Busca los identificadores de enfermedad que contienen la palabra keyword como parte del nombre de la enfermedad.
  @param keyword: string que contiene la parte del nombre de la enfermedad ha buscar.
  @return una lista de los identificadores de enfermedad que contienen la palabra keyword como parte del nombre de la enfermedad
  */
  list<IDenf> getEnfermedades(string keyword); //Utilizar enfermedad.nameContains() para programar este método.

  /**
  @brief Busca todas las mutaciones que se encuentran asociadas a la enfermedad con identificador ID.
  @param ID: ID de la enfermedad ha buscar.
  @return un conjunto ordenado (en orden creciente de IDmut) de todas las mutaciones que se encuentran asociadas
  * a la enfermedad con identificador ID. Si no tuviese ninguna enfermedad asociada, devuelve el conjunto vacío.
  */
  set<IDmut> getMutacionesEnf (IDenf ID);

  /**
  @brief Busca las mutaciones que se encuentran asociadas a un gen determinado dado por ID.
  @param ID: ID del gen ha buscar.
  @return Devuelve un conjunto de todas las mutaciones que se encuentran asociadas a un gen determinado dado por ID. Si
  * no tuviese ninguno, devuelve el conjunto vacío.
  */
  set<IDmut> getMutacionesGen (IDgen ID);

  /**
  @brief Dado un string 'keyword', el sistema recupera todas las enfermedades cuyo nombre contiene keyword.
  @param k: numero de mutaciones ha devolver.
  @param keyword: string con el nombre de la enfermedad
  @return un set ordenado de mutaciones, en orden decreciente de probabilidad, con las k mutaciones más
  * frecuentes en la población asociadas con esas enfermedades.
  */


  set<mutacion,ProbMutaciones> topKMutaciones (int k, string keyword);

  /**
  @brief hace la búsqueda por rango considerando el par de valores cromosoma/posición.
  @param cromosoma: string que contiene el cromosoma ha buscar.
  @param posicion: entero positivo que contiene el valor de la posicion.
  @return el iterador que apunta a la primera mutación que es mayor o igual a los parámetros dados en la entrada,
  * si no hay ninguna devuelve end.
  */
  iterator lower_bound(string cromosoma, unsigned int posicion);

  /**
  @brief hace la búsqueda por rango considerando el par de valores cromosoma/posición.
  @param cromosoma: string que contiene el cromosoma ha buscar.
  @param posicion: entero positivo que contiene el valor de la posicion.
  @return el iterador que apunta a la primera mutación que es estrictamente mayor a los parámetros dados en la
  * entrada, si no hay ninguna devuelve end.
  */
  iterator upper_bound(string cromosoma, unsigned int posicion);

  /**
  @brief begin del conjunto
  @return el iterador correspondiente a la primera mutación según el criterio de ordenación de cada tipo de elemento.
  */
  iterator begin();

  /**
  @brief end del conjunto.
  @return el iterador que apunta al elemento siguiente al último elemento según el criterio de ordenación de cada
  * tipo de elemento.
  */
  iterator end();

  /**
  @brief begin de enfermedad del conjunto
  @return el iterador correspondiente a la primera enfermedad según el criterio de ordenación de cada tipo de elemento.
  */
  enfermedad_iterator ebegin();

  /**
  @brief end de enfermedad del conjunto.
  @return el iterador que apunta al elemento siguiente al último elemento según el criterio de ordenación de cada
  * tipo de elemento.
  */
  enfermedad_iterator eend();

  /**
  @brief begin de enfermedad del conjunto
  @return el iterador correspondiente al primer gen según el criterio de ordenación de cada tipo de elemento.
  */
  gen_iterator gbegin();

  /**
  @brief end de gen del conjunto.
  @return el iterador que apunta al elemento siguiente al último elemento según el criterio de ordenación de cada
  * tipo de elemento.
  */
  gen_iterator gend();

  /* @brief iterador sobre mutaciones en orden creciente de cromosoma/posicion */
  class iterator {
  private:
		friend class clinvar;
    set<mutacion>::iterator it;
  public:
		/**
		@brief Constructor por defecto
		*/
		iterator(){};
		/**
		@brief Constructor de copia
		@param x: iterador para copiar su contenido
		*/
		iterator(const iterator &  x){
			*this = x;
		}
		/**
		@brief Devuelve el contenido al que apunta el iterador
		@return elemto del vector al que apunta el iterador
		*/
		const mutacion & operator*(){
			return *it;
		}
		/**
		@brief Adelanta una posicion el iterador
		@return la referencia al propio iterador
		*/
		iterator & operator++(){
			++it;
			return *this;
		}
		/**
		@brief Atrasa el iterador una posicion
		@return la referencia al propio iterador
		*/
		iterator & operator--(){
			--it;
			return *this;
		}
		/**
		@brief Compara si dos iteradores apuntan al mismo sitio
		@param x: iterador a comparar con el actual
		@return true si son iguales o false en caso contrario
		*/
		bool operator==(const iterator & x) const {
			return (it == x.it);
		}
		/**
		@brief Compara si dos iteradores no apuntan al mismo elemento
		@param x: iterador a comparar con el actual
		@return true si los iteradores son distintos, false en caso contrario
		*/
		bool operator!=(const iterator & x) const {
			return (it != x.it);
		}
		/**
		@brief Iguala dos iteradores
		@param x: iterador del que copiaremos la informacion
		@return la referencia al propio iterador
		*/
		iterator & operator=(const iterator & x){
			if( this != &x ){
				it = x.it;
			}
			return *this;
		}
		/**
		@brief Transforma un iterador de IDm_map ha iterator
		@param x: iterador del que copiaremos la informacion
		@return la referencia al propio iterador
		*/
		iterator & operator=(const unordered_map<IDmut,set<mutacion>::iterator>::iterator & x){
			it = x->second;
			return *this;
		}
  };
  /* @brief iterador sobre mutaciones considerando el orden creciente del ID del gen */
  class gen_iterator {
  public:
		/**
		@brief Constructor por defecto
		*/
		gen_iterator(){};
		/**
		@brief Constructor de copia
		@param x: iterador para copiar su contenido
		*/
		gen_iterator(const gen_iterator &  x){
			*this = x;
		}
		/**
		@brief Devuelve el contenido al que apunta el iterador
		@return elemto del vector al que apunta el iterador
		*/
		const mutacion & operator*(){
			return **itlist;
		}
		/**
		@brief Adelanta una posicion el iterador
		@return la referencia al propio iterador
		*/
		gen_iterator & operator++(){
			++itlist;
			if( itlist == itmap->second.end() ){
				++itmap;
				itlist = itmap->second.begin();
			}
			return *this;
		}
		/**
		@brief Atrasa el iterador una posicion
		@return la referencia al propio iterador
		*/
		gen_iterator & operator--(){
			if( itlist == itmap->second.begin() ){
				--itmap;
				itlist = itmap->second.end();
			}
			else{
				--itlist;
			}
			return *this;
		}
		/**
		@brief Compara si dos iteradores apuntan al mismo sitio
		@param x: iterador a comparar con el actual
		@return true si son iguales o false en caso contrario
		*/
		bool operator==(const gen_iterator & x) const {
			return (itlist == x.itlist && itmap == x.itmap && ptrclinvar == x.ptrclinvar);
		}
		/**
		@brief Compara si dos iteradores no apuntan al mismo elemento
		@param x: iterador a comparar con el actual
		@return true si los iteradores son distintos, false en caso contrario
		*/
		bool operator!=(const gen_iterator & x) const {
			return (itmap != x.itmap || itlist != x.itlist || ptrclinvar != x.ptrclinvar);
		}
		/**
		@brief Iguala dos iteradores
		@param x: iterador del que copiaremos la informacion
		@return la referencia al propio iterador
		*/
		gen_iterator & operator=(const gen_iterator & x){
			if( this != &x ){
				itlist = x.itlist;
				itmap = x.itmap;
				ptrclinvar = x.ptrclinvar;
			}
			return *this;
		}
  private:
		friend class clinvar;
    map<IDgen, list< set<mutacion>::iterator> >::iterator itmap;
    list<set<mutacion>::iterator>::iterator itlist;
    clinvar *ptrclinvar;
  };

private:
  /**
  Toda la información relativa a las mutaciones se almacena en un conjunto (set), ordenados en orden creciente de
  cromosama/posición que llamaremos mutDB.
  Es importante destacar que la inserción y borrado de elementos en un set no invalida los iteradores. Esto nos
  facilitará las labores de implementación de los métodos.
  */
  set<mutacion> mutDB; //base de datos que contiene toda la información asociada a una mutacion

  /**
  Esta estructura se utiliza para permitir un acceso eficiente por IDmut. Para cada ID de mutación, almacenamos
  un iterador al objeto completo (que está almacenado en el set mutDB). En este caso, ya que la especificación no
  nos indica que sea importante el orden entre los distintos IDmut y, además, los IDmut son únicos, utilizaremos un
  unordered_map para facilitar las operaciones de acceso (O(1)).
  Esta estructura se actualiza cada vez que se inserta o borra un nuevo elemento.
  */
  unordered_map<IDmut,set<mutacion>::iterator> IDm_map; // Asocia IDmutacion con mutación

  /**
  Esta estructura se utilizará para permitir un acceso eficiente al conjunto de mutaciones por IDgen. Resulta útil
  para los usuarios finales listar las mutaciones ordenadas según el identificador del gen, por lo que consideraremos
  este contenedor asociativo. Además, como un mismo IDgen puede estar asociado a distintas mutaciones, hemos
  optado por representar para cada IDgen la lista de iteradores que apuntan a las mutaciones asociadas a este gen
  en el set.
  Cuando una nueva mutación se inserta en mutDB se deben insertar iteradores a esta mutación en todas las listas
  de gen_map asociadas a los genes relacionados con esta mutación. En el caso de borrado de una mutación,
  también deben borrarse sus iteradores asociados del map.
  */
  map<IDgen, list< set<mutacion>::iterator> > gen_map; // Asocia genes con mutaciones

  /**
  Esta estructura se utiliza para facilitar el acceso a las enfermedades, y contendrá toda la información asociada a
  las mismas. Las tendremos ordenadas por IDenf y por tanto utilizamos un map.
  Esta estructura se actualiza cada vez que se inserta o borra una nueva mutación en el conjunto.
  */
  map<IDenf,enfermedad> EnfDB; // Base de datos de enfermedades

  /**
  Esta estructura se utiliza para facilitar el acceso a mutaciones asociadas a una enfermedad determinada. Como
  cada enfermedad puede estar asociada a varias mutaciones, proponemos en este caso un multimap en el que
  la clave (key) es el identificador de enfermedad y el valor asociado es un iterador a la mutación en el set. Esto lo
  hacemos así porque una misma enfermedad (IDenf) puede estar asociada a varias mutaciones. Por tanto, debemos
  permitir que haya varias entradas con la misma clave, y por esto utilizamos multimap. Es decir, si una enfermedad
  dada tiene asociadas N mutaciones, el multimap tendrá N entradas asociadas a dicha enfermedad, y en cada una
  de estas entradas se guardará el iterador de una de las N mutaciones.
  Esta estructura se actualiza cada vez que se inserta o borra una nueva mutación en el conjunto.
  */
  multimap<IDenf,set<mutacion>::iterator> IDenf_map; // Asocia enfermedad con mutaciones

};
