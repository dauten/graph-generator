#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>

//template< typename nodeType >
struct Edge
{
        int neighbor;

        int weight;

	Edge()
	{
		neighbor = 0;

		weight = 0;
	}

	Edge( int setNeighbor, int setWeight )
	{
		neighbor = setNeighbor;

		weight = setWeight;
	}
};

template< typename keyType, typename valueType >
using GraphList = std::map< keyType, std::map< valueType, Edge > >; 

template< typename keyType, typename valueType >
void RemoveEdges( GraphList< keyType, valueType >& graph, bool isDirected, int percentToKeep )
{
	if( percentToKeep != 100 )
	{
		int modNumber = 100 / percentToKeep;

		for( auto node = graph.begin(); node != graph.end(); ++node )
		{
			for( auto neighbor = node->second.begin(); neighbor != node->second.end(); ++neighbor )
			{
				if( std::rand() % 100 + 1 > percentToKeep )
				{
					graph.find( neighbor->first )->second.erase( node->first );

					if( isDirected == false )
					{	
						node->second.erase( neighbor->first );
					}
				}
			}
		}
	}
}

template< typename keyType, typename valueType >
void OutputGraph( GraphList< keyType, valueType >& graph, std::ostream& desiredOutput )
{
	for( auto node = graph.begin(); node != graph.end(); ++node )
        {
                desiredOutput << node->first;

                for( auto neighbor = node->second.begin(); neighbor != node->second.end(); ++neighbor )
                {
                        desiredOutput << " " << neighbor->first << ":" << neighbor->second.weight;
                }

                desiredOutput << std::endl;
        }
}

int GenerateWeight( int range )
{
	int sign = 1;

	if( std::rand() % 2 == 0 )
	{
	//	positive = -1;
	}

	return sign * ( std::rand() % range / 2 );
}

int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		std::cerr << "Usage: graph-generator <number of vertices> [edge weight range] [directed flag] [graph density 1-100]" << std::endl;

		return 1;
	}

	GraphList< int, int > graph;

	int desiredSize = std::atoi( argv[ 1 ] );

	for( int i = 0; i < desiredSize; ++i )
	{
		for( int j = i + 1; j % desiredSize != i; ++j )
		{
			graph[ i ][ j % desiredSize ] = Edge( j % desiredSize, GenerateWeight( std::atoi( argv[ 2 ] ) ) );
		}
	}

	int percentToKeep;

	if( argc < 4 )
	{
		percentToKeep = 100;
	}

	else
	{
		percentToKeep = std::atoi( argv[ 4 ] );
	}

	bool directed = false;

	if( argc >= 3 )
	{
		directed = std::atoi( argv[2] );
	}

	RemoveEdges( graph, directed, percentToKeep );

	OutputGraph( graph, std::cout );

	return 0;
}

