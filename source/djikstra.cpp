#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

int main()
{
	std::map< int, std::map< int, int > > graph;

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

	for( auto node = graph.begin(); node != graph.end(); ++node )
	{
		std::cout << node->first;

		for( auto edge = node->second.begin(); edge != node->second.end(); ++edge )
		{
			std::cout << " " << edge->first << ":" << edge->second;
		}

		std::cout << std::endl;
	}
}
