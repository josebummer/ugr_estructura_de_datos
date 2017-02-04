#include "Nmer.h"

#include <fstream>

template<typename T, int K>
extern void recorrido_preorden(typename ktree<T,K>::const_node n);


Nmer::Nmer() {
  max_long = 0;
  el_Nmer = ktree<pair<char,int>,4>(pair<char,int>('-',0));
}

bool Nmer::loadSerialized(const string & fichero) {
 string cadena;
 ifstream fe;
 pair<char,int> nulo('x',-1);
 Nmer::String2Base stb;

 fe.open(fichero.c_str(), ifstream::in);
 if (fe.fail()){
    cerr << "Error al abrir el fichero " << fichero << endl;
 }
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    } while (cadena.find("#")==0 && !fe.eof());
    // leemos Nmer_length
     max_long = std::stoi(cadena);
     // leemos cadena serializada
    getline(fe,cadena,'\n');
    el_Nmer.deserialize(cadena,nulo,';',stb);
    fe.close();
    return true;
 } // else
 fe.close();typename ktree<pair<char,int>,4>::const_node::child_iterator ini;
  typename ktree<pair<char,int>,4>::const_node::child_iterator fin;
 return false;
}

void Nmer::recorrer_mostrar(typename ktree<pair<char,int>,4>::const_node n,string &elem) const{
  if (!n.null()){
    elem.push_back((*n).first);
    cout << "( " << elem << "," << (*n).second <<" ); " <<endl;
    if(elem[0] == '-')
      elem.clear();
    typename ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    typename ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();
    while (ini!=fin){
      recorrer_mostrar(*ini,elem);
      elem.pop_back();
       ++ini;
     }
   }
}

void Nmer::list_Nmer() const {
    // implmenentar el recorrido en preorden para el ktree de forma que nos devuelva los Nmers completos y no sólo el nodo.
    ktree<pair<char,int>,4>::const_node n;
    n = el_Nmer.root();
    string elem;
    recorrer_mostrar(n,elem);
}

unsigned int Nmer::length() const {
   return max_long;
}

Nmer::size_type Nmer::size() const{
  return el_Nmer.size()-1;
}

Nmer & Nmer::operator=(const Nmer & a){
  if( this != &a ){
    this->el_Nmer = a.el_Nmer;
    this->max_long = a.max_long;
  }
  return *this;
}

Nmer::Nmer(const Nmer &otro){
  *this = otro;
}

bool Nmer::containsString(const string adn) const{
  typename ktree<pair<char,int>,4>::const_node n;
  n =  this->el_Nmer.root();
  bool esta = true;
  unsigned int i = 0;

  typename ktree<pair<char,int>,4>::const_node::child_iterator ini;
  typename ktree<pair<char,int>,4>::const_node::child_iterator fin;

  while ( i < adn.size() && esta ){
    ini = n.begin();
    fin = n.end();
    while( ini!=fin && (*(*ini)).first!=adn[i] ){
      ini++;
    }
    if( ini != fin ){
      n = *ini;
    }
    else{
      esta = false;
    }
     i++;
   }
   if(esta){
     return true;
   }
   return false;
}

bool Nmer::included(const Nmer &reference) const{
  set<pair<string,int> > content;
  string elem;
  bool res;

   recorrerGuardar(el_Nmer.root(),elem, content ,0,false);

   for( auto it = content.begin(); it != content.end(); ++it ){
     res = reference.containsString((*it).first);
     if( !res )
      return false;
   }
   return true;
}

void Nmer::sequenceADN(unsigned int l, const string & adn){
  max_long = l;
  el_Nmer.assing(pair<char,int>('-',0));
  string palabra;

  for( unsigned i = 0; i < adn.size(); i++ ){
    palabra.clear();
    for(unsigned j = i; j < i+l && j < adn.size(); j++){
      palabra.push_back(adn[j]);
    }
    insertar_cadena(palabra);
  }
}

unsigned Nmer::getPosicion(char elem) const{
  switch (elem) {
    case 'A':
    case 'a':
      return 0;
    break;
    case 'G':
    case 'g':
      return 1;
    break;
    case 'C':
    case 'c':
      return 2;
    break;
    case 'T':
    case 't':
      return 3;
    break;
    default:
      return -1;
    break;
  }
}

void Nmer::insertar_cadena(const string & cadena){
  ktree<pair<char,int>,4>::node n = el_Nmer.root();
  unsigned pos;

  for( unsigned i = 0; i < cadena.size(); i++ ){
      pos = getPosicion(cadena[i]);
      if( n.k_child(pos).null() ){
        el_Nmer.insert_k_child(n,pos,pair<char,int>(cadena[i],1));
      }
      else{
        (*(n.k_child(pos))).second++;
      }
      n = n.k_child(pos);
  }
}

Nmer Nmer::Prefix(const string &adn){
  typename ktree<pair<char,int>,4>::node n = el_Nmer.root();
  ktree<pair<char,int>,4> arbol;
  bool esta = true;
  Nmer res;
  string elem;
  unsigned int i = 0;

  while ( i < adn.size() && esta ){
    auto ini = n.begin();
    auto fin = n.end();
    while( ini!=fin && (*(*ini)).first!=adn[i] ){
      ini++;
    }
    if( ini != fin ){
      n = *ini;
    }
    else{
      esta = false;
    }
     i++;
   }
   if(esta){
     arbol.assing(el_Nmer,n);
     res.el_Nmer.insert_k_child(res.el_Nmer.root(),getPosicion(adn[adn.size()-1]),arbol);
     res.max_long = max_long - (adn.size()-1);
   }
   return res;
}

void Nmer::recorrerGuardar(typename ktree<pair<char,int>,4>::const_node n,string &elem, set<pair<string,int> > &s, int t, bool cre)const {
  if (!n.null()){
    elem.push_back((*n).first);
    if(elem[0] == '-')
      elem.clear();
    else if( cre ){
      if((*n).second <= t)
        s.insert(pair<string,int>(elem,(*n).second));
    }
    else{
      if((*n).second > t)
        s.insert(pair<string,int>(elem,(*n).second));
    }

    typename ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    typename ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();

    while (ini!=fin){
      recorrerGuardar(*ini,elem,s,t,cre);
      elem.pop_back();
       ++ini;
     }
   }
}

set <pair<string,int> ,OrdenCre > Nmer::rareNmer(int threshold) const{
  string sub;
  set <pair<string,int> > s;
  set <pair<string,int> ,OrdenCre > res;
  typename set <pair<string,int> ,OrdenCre >::iterator it2;
  typename set <pair<string,int> ,OrdenCre >::iterator it;
  typename ktree<pair<char,int>,4>::const_node n = el_Nmer.root();

  recorrerGuardar(n,sub,s,threshold,true);
  it2 = s.begin();
  ++it2;

  for( it = s.begin(); it2 != s.end(); ++it,++it2 ){
    if( ((*it2).first.find((*it).first,0)) != 0 ){
      res.insert(*it);
    }
  }
  res.insert(*it);

  return res;
}

set <pair<string,int> ,OrdenDecre > Nmer::commonNmer(int threshold) const{
  string sub;
  set <pair<string,int> > s;
  set <pair<string,int> ,OrdenDecre > res;
  typename set <pair<string,int> ,OrdenDecre >::iterator it2;
  typename set <pair<string,int> ,OrdenDecre >::iterator it;
  typename ktree<pair<char,int>,4>::const_node n = el_Nmer.root();

  recorrerGuardar(n,sub,s,threshold,false);
  it2 = s.begin();
  ++it2;

  for( it = s.begin(); it2 != s.end(); ++it,++it2 ){
    if( ((*it2).first.find((*it).first,0)) != 0 ){
      res.insert(*it);
    }
  }
  res.insert(*it);

  return res;
}

set<pair<string,int> , OrdenCre > Nmer::level(int l) const{
  string sub;
  set <pair<string,int> > s;
  set <pair<string,int> ,OrdenCre > res;
  typename ktree<pair<char,int>,4>::const_node n = el_Nmer.root();

  recorrerGuardar(n,sub,s,0,false);

  for( auto it = s.begin(); it != s.end(); ++it ){
    if( (*it).first.length() == (unsigned) l ){
      res.insert(*it);
    }
  }

  return res;
}

float Nmer::Distance(const Nmer &otro) const{
  set <pair<string,int> ,OrdenDecre > resthis;
  set <pair<string,int> ,OrdenDecre > resotro;
  unordered_map<string,int> rankthis;
  unordered_map<string,int> rankotro;
  string sub;
  set <pair<string,int> > aux;

  recorrerGuardar(el_Nmer.root(),sub,aux,0,false);
  for( auto it = aux.begin(); it != aux.end(); ++it ){
      resthis.insert(*it);
  }
  sub.clear();
  aux.clear();
  recorrerGuardar(otro.el_Nmer.root(),sub,aux,0,false);
  for( auto it = aux.begin(); it != aux.end(); ++it ){
      resotro.insert(*it);
  }

  int i = 1;
  float dist = 0;
  int posx,posy,valor;
  int max = (resthis.size() < resotro.size())?resotro.size():resthis.size();

  for(auto it = resthis.begin(); it != resthis.end(); ++it){
    rankthis[(*it).first] = i;
    i++;
  }

  i = 1;
  for(auto it = resotro.begin(); it != resotro.end(); ++it){
    rankotro[(*it).first] = i;
    i++;
  }

  for(auto it = rankthis.begin(); it != rankthis.end(); ++it){
    auto it2 = rankotro.find(it->first);
    if(  it2 != rankotro.end()  ){
      posx = it->second;
      posy = it2->second;
      valor = abs(posx-posy)/max;
    }
    else{
      valor = 1;
    }
    dist += valor;
  }
  return dist/resthis.size();
}

Nmer Nmer::Union(const Nmer &reference) const{
  Nmer res;
  string elem;
  set<pair<string,int> ,OrdenCre> datosthis;
  set<pair<string,int> ,OrdenCre> datosref;

   datosthis = level(this->max_long);
   datosref = level(reference.max_long);

   for( auto it = datosthis.begin(); it != datosthis.end(); ++it ){
     for( int i = 0; i < (*it).second; i++ )
      res.insertar_cadena((*it).first);
   }
   for( auto it = datosref.begin(); it != datosref.end(); ++it ){
     for( int i = 0; i < (*it).second; i++ )
      res.insertar_cadena((*it).first);
   }

   return res;
}
