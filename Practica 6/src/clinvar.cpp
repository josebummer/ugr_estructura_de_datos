/*
Creado por: Jose Antonio Ruiz.

Practica 6 ED :
Universidad de Granada
*/

#include <iostream>
#include <queue>
#include <fstream>
#include <unordered_set>
#include <cstdio>
#include <cassert>
#include "clinvar.h"

void clinvar::load (string nombreDB){
  ifstream fe;
  string cadena;

  cout << "Abrimos "<< nombreDB << endl;
  nombreDB = "datos/"+nombreDB;
  fe.open(nombreDB, ifstream::in);
  if (fe.fail()){
    cerr << "Error al abrir el fichero " << nombreDB << endl;
  }
  else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    }while (cadena.find('#')!=string::npos && !fe.eof());

    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof() ){
      //cout << "leo:: "<< cadena << endl;
      // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
      mutacion mut = mutacion(cadena);
      //cout << mut<< endl;
      // Insertar mutación en el conjunto
      insert(mut);
      getline(fe,cadena,'\n');
    }
    fe.close();
  } // else
  fe.close();
}

void clinvar::insert (const mutacion & x){
  pair<set<mutacion>::iterator,bool> res;
  res = mutDB.insert(x);
  if(res.second == true){
    IDm_map.insert(pair<IDmut,set<mutacion>::iterator>(x.getID(),res.first));
    for( int i = 0; i < x.getGenes().size(); i++){
      gen_map[x.getGenes()[i]].push_back(res.first);
    }
    for(int i = 0 ; i < x.getEnfermedades().size(); i++){
      EnfDB[x.getEnfermedades()[i].getID()] = x.getEnfermedades()[i];
      IDenf_map.insert(pair<IDenf,set<mutacion>::iterator>(x.getEnfermedades()[i].getID(),res.first));
    }
  }
}

bool clinvar::erase (IDmut ID){
  unordered_map<IDmut,set<mutacion>::iterator>::iterator it = IDm_map.find(ID);
  if( it == IDm_map.end() ){
    return false;
  }
  multimap<IDenf,set<mutacion>::iterator>::iterator it2;
  for( it2 = IDenf_map.begin(); it2 != IDenf_map.end(); ++it2 ){
    if ( it2->second == it->second ){
      if( IDenf_map.count(it2->first) == 1){
        EnfDB.erase(it2->first);
      }
      IDenf_map.erase(it2);
    }
  }
  for( int i = 0; i < it->second->getGenes().size(); i++){
    gen_map[it->second->getGenes()[i]].remove(it->second);
    if( gen_map[it->second->getGenes()[i]].empty() ){
      gen_map.erase(it->second->getGenes()[i]);
    }
  }
  mutDB.erase(*(it->second));
  IDm_map.erase(ID);

  return true;
}

clinvar::iterator clinvar::find_Mut (IDmut ID){
  clinvar::iterator it = end();
  unordered_map<IDmut,set<mutacion>::iterator>::iterator it2;
  it2 = IDm_map.find(ID);
  if( it2 != IDm_map.end() ){
    it = it2;
  }
  return it;
}

clinvar::enfermedad_iterator clinvar::find_Enf(IDenf ID){
  return EnfDB.find(ID);
}

vector<enfermedad> clinvar::getEnfermedades(mutacion & mut){
  return mut.getEnfermedades();
}

list<IDenf> clinvar::getEnfermedades(string keyword){
  list<IDenf> res;
  for( clinvar::enfermedad_iterator eit = ebegin(); eit != eend(); ++eit ){
    if( eit->second.nameContains(keyword) ){
      res.push_back(eit->first);
    }
  }
  return res;
}

set<IDmut> clinvar::getMutacionesEnf (IDenf ID){
  set<IDmut> res;
  multimap<IDenf,set<mutacion>::iterator>::iterator it;
  pair<multimap<IDenf,set<mutacion>::iterator>::iterator,multimap<IDenf,set<mutacion>::iterator>::iterator> p;
  p = IDenf_map.equal_range(ID);
  for( it = p.first; it != p.second; ++it ){
    res.insert(it->second->getID());
  }
  return res;
}

set<IDmut> clinvar::getMutacionesGen (IDgen ID){
  set<IDmut> res;
  map<IDgen, list< set<mutacion>::iterator> >::iterator git = gen_map.find(ID);
  if( git == gen_map.end() ){
    return res;
  }
  list< set<mutacion>::iterator> l = git->second;
  list< set<mutacion>::iterator>::iterator it;
  for( it = l.begin(); it != l.end(); ++it ){
    res.insert((*it)->getID());
  }
  return res;
}

set<mutacion,ProbMutaciones> clinvar::topKMutaciones (int k, string keyword){
  set<IDmut> aux;
  unordered_set<IDmut> smut;
  unordered_set<IDmut>::iterator uit;
  list<IDenf> lenf;
  priority_queue<mutacion,vector<mutacion>,ProbMutaciones> q;

  lenf = getEnfermedades(keyword);
  for( list<IDenf>::iterator it = lenf.begin(); it != lenf.end(); ++it ){
    aux = getMutacionesEnf(*it);
    smut.insert( aux.begin() , aux.end() );
  }
  int i = 0;
  for( uit = smut.begin(); i < k && uit != smut.end(); i++,++uit ){
    q.push(*(find_Mut(*uit)));
  }
  if( uit != smut.end() ){
    for( uit = uit; uit != smut.end(); ++uit ){
      if( (*find_Mut(*uit)).getCaf()[0] < q.top().getCaf()[0] ){
        q.pop();
        q.push(*(find_Mut(*uit)));
      }
    }
  }
  set<mutacion,ProbMutaciones> res;
  while( !q.empty() ){
    res.insert(q.top());
    q.pop();
  }
  return res;
}

clinvar::iterator clinvar::lower_bound(string cromosoma, unsigned int posicion){
  clinvar::iterator it;
  for( it = begin(); it != end(); ++it ){
    if( (*it).getChr() >= cromosoma && (*it).getPos() >= posicion ){
      return it;
    }
  }
  return it;
}

clinvar::iterator clinvar::upper_bound(string cromosoma, unsigned int posicion){
  clinvar::iterator it;
  for( it = begin(); it != end(); ++it ){
    if( (*it).getChr() > cromosoma && (*it).getPos() > posicion ){
      return it;
    }
  }
  return it;
}

clinvar::iterator clinvar::begin(){
  clinvar::iterator aux;
  aux.it = mutDB.begin();
  return aux;
}

clinvar::iterator clinvar::end(){
  clinvar::iterator aux;
  aux.it = mutDB.end();
  return aux;
}

clinvar::enfermedad_iterator clinvar::ebegin(){
  clinvar::enfermedad_iterator aux = EnfDB.begin();
  return aux;
}

clinvar::enfermedad_iterator clinvar::eend(){
  clinvar::enfermedad_iterator aux = EnfDB.end();
  return aux;
}

clinvar::gen_iterator clinvar::gbegin(){
  clinvar::gen_iterator aux;
  aux.itmap = gen_map.begin();
  aux.itlist = aux.itmap->second.begin();
  aux.ptrclinvar = this;
  return aux;
}

clinvar::gen_iterator clinvar::gend(){
  clinvar::gen_iterator aux;
  aux.itmap = gen_map.end();
  aux.itlist = aux.itmap->second.begin();
  aux.ptrclinvar = this;
  return aux;
}
