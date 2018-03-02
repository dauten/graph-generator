#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>

typedef std::map< int, std::map< int, int > > GraphList; 

void RemoveEdges( GraphList& graph, int percentToKeep = 100 )
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

                                	node->second.erase( neighbor->first );
	                        }
        	        }
	        }
	}
}

void OutputGraph( GraphList& graph, std::ostream& desiredOutput )
{
	for( auto node = graph.begin(); node != graph.end(); ++node )
        {
                desiredOutput << node->first;

                for( auto neighbor = node->second.begin(); neighbor != node->second.end(); ++neighbor )
                {
                        desiredOutput << " " << neighbor->first << ":" << neighbor->second;
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

GraphList GenerateUndirectedGraph( int desiredSize, int weightRange )
{
	GraphList newGraph;

	for( int i = 0; i < desiredSize; ++i )
        {
                for( int j = i + 1; j % desiredSize != i; ++j )
                {
                        int neighbor = j % desiredSize;

                        int weight = GenerateWeight( weightRange );

                        newGraph[ i ][ j % desiredSize ] = weight ;

                        newGraph[ neighbor ][ i ] = weight;
                }
        }

	return newGraph;
}

int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		std::cerr << "Usage: graph-generator <number of vertices> [weight range]" << std::endl;

		return 1;
	}

	GraphList graph = GenerateUndirectedGraph( std::atoi( argv[ 1 ] ), std::atoi( argv[ 2 ] ) );

	RemoveEdges( graph, std::atoi( argv[ 3 ] ) );

	OutputGraph( graph, std::cout );

	return 0;
}

