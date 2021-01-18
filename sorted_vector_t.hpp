/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 13 Algoritmos Divide y Vencerás
 * @author Ayob Asrout Vargas
 * @date 14/01/2021
 * Contact: alu0101350158@ull.edu.es
 * Compilation: g++ -std=c++14 -g -Wall main.cpp sorted_vector_t.cpp -o main
 */
#pragma once 

#include <vector>
#include <iostream>

using namespace std;


namespace CyA {
  class sorted_vector_t: public vector<int> {
   public:
    sorted_vector_t(void):
    vector<int>() {}
      
    sorted_vector_t(const vector<int>& v):
    vector<int>(v) {}
      
    ~sorted_vector_t(void) {}
    
    void merge_sort(void);
    void merge_sort_ite(void);
      
    void write(ostream& os) const;    
      
   private:    
    void create_vector_sentinel(int l, int r, vector<int>& v);
    void merge(const vector<int>& v1, const vector<int>& v2, int l);
      
    void merge_sort(int l, int r);
    void merge(int l, int c, int d);
  };
}

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v);
