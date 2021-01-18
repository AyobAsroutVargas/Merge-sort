/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 13 Algoritmos Divide y Vencerás
 * @author Ayob Asrout Vargas
 * @date 14/01/2021
 * Contact: alu0101350158@ull.edu.es
 * Compilation: g++ -std=c++14 -g -Wall main.cpp sorted_vector_t.cpp -o main
 */

#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t.hpp"

using namespace std;

int main(void)
{	
    const int kLimit = 999;
    const int kSize = 80;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-kLimit, kLimit);    
    
    CyA::sorted_vector_t v;
    
    for(int i = 0; i < kSize; i++)
        v.push_back(distribution(generator));
        
    cout << v << endl;
    
    v.merge_sort_ite();
    
    cout << v << endl;
    
	return 0;
}
