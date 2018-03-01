#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>

template< typename keyType, typename valueType >
using GraphList = std::map< keyType, std::set< valueType > >; 

template< typename keyType, typename valueType >
void RemoveEdges( GraphList< keyType, valueType >& graph )
{
        for( auto node = graph.begin(); node != graph.end(); ++node )
        {
                for( auto neighbor = node->second.begin(); neighbor != node->second.end(); ++neighbor )
                {
                        if( std::rand() % 2 == 0 )
                        {
                                graph.find( *neighbor )->second.erase( node->first );

                                node->second.erase( neighbor );
                        }
                }
        }
}


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

	RemoveEdges( graph );

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

