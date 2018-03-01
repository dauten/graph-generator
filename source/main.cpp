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

	for( int i = 0; i < std::atoi( argv[ 1 ] ); ++i )
	{
		graph[ i ].insert( i );
	}

	for( auto node = graph.begin(); node != graph.end(); ++node )
	{
		std::cout << node->first << ": " << *(node->second.begin()) << std::endl;
	}

	return 0;
}
