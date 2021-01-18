/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 13 Algoritmos Divide y Vencerás
 * @author Ayob Asrout Vargas
 * @date 14/01/2021
 * Contact: alu0101350158@ull.edu.es
 * Compilation: g++ -std=c++14 -g -Wall main.cpp sorted_vector_t.cpp -o main
 */

#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>

namespace CyA {

  void sorted_vector_t::merge_sort(void) {
    merge_sort(0, size() - 1);
  }

  void sorted_vector_t::write(ostream& os) const {
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
      os << setw(5) << at(i);
    os << "> ";
  }


  void sorted_vector_t::merge_sort(int l, int r) {
    if (l < r) {    
      int c = (l + r) / 2;

      merge_sort(l, c);
      merge_sort(c + 1, r);
      merge(l, c, r);
    }
  }


  ////////////////////////////////////////////////////////////////////////////
  // FUSIÓN CON CENTINELA
  ////////////////////////////////////////////////////////////////////////////

  // inserta en v los valores del vector comprendidos entre l y r
  // tambien añade el valor INT_MAX.
  void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v) {
    for (int i = l; i <= r; i++) {
      v.push_back(at(i));
    }
    v.push_back(INT_MAX);
  }

  // fusiona los valores del vector en el rango (ya ordenado) l-r
  void sorted_vector_t::merge(int l, int c, int r) {
    int i = 0, j = 0;
    std::vector<int> lower_bound_sentinel {}, upper_bound_sentinel {};

    create_vector_sentinel(l, c, lower_bound_sentinel);
    create_vector_sentinel(c + 1, r, upper_bound_sentinel);

    for (int k = l; k <= r; k++) {
      if (lower_bound_sentinel[i] < upper_bound_sentinel[j]) {
        at(k) = lower_bound_sentinel[i];
        i++;
      } else {
        at(k) = upper_bound_sentinel[j];
        j++;
      }
    }
  }

  ////////////////////////////////////////////////////////////////////////////
  // Merge sort iterativo
  ////////////////////////////////////////////////////////////////////////////
  void sorted_vector_t::merge_sort_ite(void) {
    int last_element_index = size() - 1;

    for (int current_size = 1; current_size <= last_element_index; current_size = 2 * current_size) {
      for (int left_start = 0; left_start < last_element_index; left_start += 2 * current_size) {

        int mid = min((left_start + current_size - 1), (last_element_index));
        int right_end =  min((left_start + (2 * current_size) - 1), (last_element_index));
        merge(left_start, mid, right_end);
      }
    }
  }

  int min(int a, int b) {
    return (a < b)? a : b;
  }
}


ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v){
  v.write(os);
  return os;
}
