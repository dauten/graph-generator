# Graph Generator


This program will generate graphs

Here is an example of a line of the data

> 0 1:4 2:4 3:1 4:4 5:4 6:2 7:1 8:1 9:4

The first number is the vertex label.

Each pair of numbers after that is an edge from that vertex. The number before the colon is the neighbor and the number after the colon is the edge weight.

It will output to stdout so use redirection to create any files you may need.

If you feel you can make it better, feel free to do so and do a pull request.

To use the program, first you must compile it using make.

The command is then 

> graph-generator <number of vertices> [edge weight range] [directed flag] [graph density 1-100]
  
Edge weight range is the range you want the weights to be for edges.

Directed Flag is to indicate if this graph is directed or undirected. Default is undirected.

Graph density allows you to control the sparsity of graphs. Use a whole number from 1-100. This is the percentage of edges that will remain. Default is 100.

Currently, it can generate disjoint graph sets, where one file is really several different graphs. This occurs more frequently as you make the graph more sparse. A flag is to be added later to switch this effect on or off.

Currently, edge weights are only positive. A flag is to be added to switch on negative weight edges.
