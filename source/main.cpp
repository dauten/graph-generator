#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <random>

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
					if( node->second.size() > 1 && graph.find( neighbor->first )->second.size() > 1 ) 
					{
                        	        	graph.find( neighbor->first )->second.erase( node->first );

	                                	node->second.erase( neighbor->first );
					}
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

GraphList GenerateUndirectedGraph( int desiredSize, int average, int stddev )
{
	std::default_random_engine generator;

	std::normal_distribution< double > distribution( average, stddev );
	
	GraphList newGraph;

	for( int i = 0; i < desiredSize; ++i )
        {
                for( int j = i + 1; j % desiredSize != i; ++j )
                {
                        int neighbor = j % desiredSize;

			int weight = std::ceil( distribution( generator ) );

                        newGraph[ i ][ j % desiredSize ] = weight;

                        newGraph[ neighbor ][ i ] = weight;
                }
        }

	return newGraph;
}

int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		std::cerr << "Usage: graph-generator <number of vertices> <average weight> <stdev weight> <percent edges to keep>" << std::endl;

		return 1;
	}

	GraphList graph = GenerateUndirectedGraph( std::atoi( argv[ 1 ] ), std::atoi( argv[ 2 ] ), std::atoi( argv[ 3 ] ) );

	RemoveEdges( graph, std::atoi( argv[ 4 ] ) );

	OutputGraph( graph, std::cout );

	return 0;
}

