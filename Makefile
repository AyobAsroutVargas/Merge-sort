CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

main: main.o sorted_vector_t.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp sorted_vector_t.hpp
	$(CXX) -c main.cpp 

sorted_vector_t.o: sorted_vector_t.cpp sorted_vector_t.hpp
	$(CXX) -c sorted_vector_t.cpp

clean:
	rm main *.o 
