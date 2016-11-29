#include "mutacion.h"
#include "enfermedad.h"
#include "conjunto.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class comp_id_crec{
public:
  bool operator() (const mutacion& a, const mutacion& b){
    return (a.getID() < b.getID());
  }
};

class comp_decr_id{
public:
  bool operator() (const mutacion &a, const mutacion &b){
    return( a.getID()  > b.getID() );
  }
};

class comp_enf_crec{
public:
  bool operator() (const enfermedad &a, const enfermedad &b){
    return( a < b );
  }
};

class comp_enf_decr{
public:
  bool operator() (const enfermedad &a, const enfermedad &b){
    return( !(a < b) );
  }
};

typedef conjunto<mutacion,less<mutacion> > conjuntomutless;
typedef conjunto<mutacion,greater<mutacion> > conjuntomutgreater;
typedef conjunto<mutacion,comp_id_crec > conjuntomutidcrec;

	/** @brief lee un fichero de mutaciones, linea a linea
	@param[in] s nombre del fichero
  @param[in,out] cm objeto tipo conjunto sobre el que se almacenan las mutaciones
	@return true si la lectura ha sido correcta, false en caso contrario
	*/
template <typename T, typename CMP>
bool load(conjunto<T,CMP> &  cm, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail()){
   cerr << "Error al abrir el fichero " << s << endl;
 }
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    }while (cadena.find("#")==0 && !fe.eof());

    //leo la tabla de mutaciones, una línea cada vez
    // while ( !fe.eof() ){
    int i = 0;
    while( i < 9000){
        //cout << "leo:: "<< cadena << endl;
        // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
        mutacion mut = mutacion(cadena);
        // Insertar mutación en el conjunto
        cm.insert(mut);
        getline(fe,cadena,'\n');
        i++;
    }
    fe.close();
    return true;
  } // else
  fe.close();
  return false;
 }

int main(int argc, char *argv[]){

    conjuntomutless conjuntoMutaciones;
    conjuntomutidcrec conjuntoMutacionesIDCrec;
    string query_str;
    int a;

    //Cargar las mutaciones en vectorSNPs
    load(conjuntoMutaciones, "clinvar_20160831.vcf");
    load(conjuntoMutacionesIDCrec, "clinvar_20160831.vcf");
    //Imprimir número de elementos almacenados en conjuntoMutaciones
    cout << endl << "HEMOS ACOTADO EL NUMERO DE MUTACIONES PARA QUE SEA MAS RAPIDO." << endl << endl;
    cout << "Lectura del fichero finalizada. Mutaciones cargadas: "<<conjuntoMutacionesIDCrec.size()<<endl << endl;


    // for( conjuntomutidcrec::iterator it = conjuntoMutacionesIDCrec.begin(); it != conjuntoMutacionesIDCrec.end(); ++it){
    //   conjuntoMutacionesIDCrec.getElem(it);
    // }
    // exit(-1);

    /**Imprimir cuántas mutaciones están asociadas al cromosoma 1: */
    mutacion m;
    m.setChr("2");
    m.setPos(1);
    a = conjuntoMutaciones.lower_bound(m) - conjuntoMutaciones.begin();
    cout << "Mutaciones asociadas a Chr 1: "<< a<< endl << endl;

    /**@todo ¿Existe la mutación con ID "rs147165522"? Imprimir la mutación y las enfermedades asociadas */
    cout << "¿Existe la mutación con ID rs147165522?" << endl;
    mutacion m2;
    m2.setID("rs147165522");
    conjuntomutidcrec::iterator it = conjuntoMutacionesIDCrec.upper_bound(m2);
    if( it != conjuntoMutacionesIDCrec.end() ){
      conjuntoMutacionesIDCrec.getElem(it);
    }
    else{
      cout << "No existe una mutacion con ID rs147165522" << endl;
    }
    //  /**@todo ¿Existe la mutación en chr/pos "14"/67769578? Imprimir la mutación y las enfermedades asociadas */
     cout << endl << "¿Existe la mutación en chr/pos 14/67769578?" << endl;
    m.setChr("14");
    m.setPos(67769578);
    conjuntomutless::iterator res = conjuntoMutaciones.find(m);
    if ( res < conjuntoMutaciones.end() ){
      conjuntoMutaciones.getElem(res);
    }
    else{
      cout << "No existe mutacion con chr/pos -- 14/67769578" << endl;
    }
    // /**@todo ¿Cómo podríamos calcular el número de mutaciones del cromosoma 2? (utiliza lower_bound / upper_bound) */
    cout << endl << "¿Cómo podríamos calcular el número de mutaciones del cromosoma 2?" << endl;
    m.setChr("3");
    m.setPos(1);
    m2.setChr("2");
    m2.setPos(1);
    a = conjuntoMutaciones.lower_bound(m) - conjuntoMutaciones.lower_bound(m2);
    cout << "Mutaciones asociadas a Chr 2: "<< a<< endl << endl;
    /**@todo Analiza la eficiencia teórica y empírica de las operaciones find, insert y erase */

   return 0;
}
