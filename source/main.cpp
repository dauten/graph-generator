#include <iostream>
#include <map>
#include <set>
#include <string>

template< typename keyType, typename valueType >
using GraphList = std::map< keyType, std::set< valueType > >; 

int main( int argc, char* argv[] )
{
	if( argc != 2 )
	{
		std::cerr << "Usage: graph-generator <number of vertices>" << std::endl;

		return 1;
	}

	GraphList< int, int > graph;

	int desiredSize = std::atoi( argv[ 1 ] );

	for( int i = 0; i < desiredSize; ++i )
	{
		std::cout << "i = " << i << std::endl;

		for( int j = i + 1; j % desiredSize != i; ++j )
		{
			std::cout << "\tj % desiredSize = " << j % desiredSize << std::endl;

			graph[ i ].insert( j % desiredSize );
		}
	}

	for( auto node = graph.begin(); node != graph.end(); ++node )
	{
		std::cout << node->first << ":";

		for( auto neighbor = node->second.begin(); neighbor != node->second.end(); ++neighbor )
		{
			std::cout << " " << *neighbor;
		}

		std::cout << std::endl;
	}

	return 0;
}
