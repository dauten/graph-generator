#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include <set>

typedef std::map< int, std::map< int, int > > GraphList;

const int maxInt = std::numeric_limits<int>::max();

int FindNextNode( const std::map< int, int >& distances, const std::set< int >& visitedSet )
{
	int currentMin = maxInt;

	int minNodeId = -1;

	for( auto node = distances.begin(); node != distances.end(); ++node )
	{
		if( node->second < currentMin && visitedSet.find( node->first ) == visitedSet.end() )
		{
			currentMin = node->second;

			minNodeId = node->first;
		}	
	}

	return minNodeId; 
}

std::map< int, int > Djikstra( GraphList& graph, int origin )
{
	std::map< int, int > distances;

	for( auto node = graph.begin(); node != graph.end(); ++node )
	{
		distances[ node->first ] = maxInt;
	}

	distances[ origin ] = 0;

	std::set< int > visitedNodes;

	for( unsigned int i = 0; i < graph.size() - 1; ++i )
	{
		auto currentNode = FindNextNode( distances, visitedNodes );

		visitedNodes.insert( currentNode );

		for( auto neighbor = graph[ currentNode ].begin(); neighbor != graph[ currentNode ].end(); ++neighbor )
		{
			if( distances[ currentNode ] + neighbor->second < distances[ neighbor->first ] )
			{
				distances[ neighbor->first ] = distances[ currentNode ] + neighbor->second;
			}
		}
	}

	return distances;	
}

int main()
{
	GraphList graph;

	std::string node;

	std::string neighbor;

	std::string weight;

	std::vector< std::stringstream > lines;

	while( std::getline( std::cin, node ) )
	{
		lines.push_back( std::stringstream( node ) );
	}

	for( unsigned int i = 0; i < lines.size(); ++i )
	{
		std::getline( lines[ i ], node, ' ' );

		while( std::getline( lines[ i ], neighbor, ':' ) )
		{
			std::getline( lines[ i ], weight, ' ' );

			graph[ std::stoi( node ) ][ std::stoi( neighbor ) ] = std::stoi( weight );
		}
	}

	std::map< int, std::map< int, int > > distanceMatrix;

	for( auto node = graph.begin(); node != graph.end(); ++node )
	{
		distanceMatrix[ node->first ] = Djikstra( graph, node->first );			
	}

	for( auto node = distanceMatrix.begin(); node != distanceMatrix.end(); ++node )
	{
		for( auto distance = node->second.begin(); distance != node->second.end(); ++distance )
		{
			if( distance->second != maxInt )
			{
				std::cout << distance->second << " ";
			}

			else
			{
				std::cout << -1 << " ";
			}
		}

		std::cout << std::endl;
	}

	return 0;
}
