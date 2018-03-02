all: graph-generator djikstra

graph-generator: source/main.cpp
	g++ -std=c++11 source/main.cpp -o graph-generator 

djikstra: source/djikstra.cpp
	g++ -std=c++11 source/djikstra.cpp -o djikstra
