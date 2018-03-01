all: graph-generator

graph-generator: source/main.cpp
	g++ -std=c++11 source/main.cpp -o graph-generator 
