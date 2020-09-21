
CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings)

all: main

clean:
	rm pe3_references.o main

main: pe3_references.o pe3_references.cpp
	$(CXX) $(CXXFLAGS) main.cpp pe3_references.o -o main
    
Pe3_references.o: pe3_references.cpp
	$(CXX) $(CXXFLAGS) -c pe3_references.cpp