# Graph Generator


This program will generate graphs

They will look like

0 1:4 2:4 3:1 4:4 5:4 6:2 7:1 8:1 9:4
1 0:1 2:1 3:4 4:3 5:1 6:4 7:2 8:3 9:3
2 0:1 1:2 3:4 4:0 5:1 6:3 7:2 8:0 9:3
3 0:4 1:1 2:0 4:0 5:3 6:1 7:3 8:2 9:1
4 0:0 1:2 2:2 3:4 5:1 6:2 7:3 8:4 9:2
5 0:2 1:3 2:4 3:4 4:3 6:1 7:1 8:3 9:3
6 0:4 1:4 2:1 3:3 4:4 5:4 7:2 8:0 9:2
7 0:2 1:1 2:0 3:1 4:0 5:0 6:3 8:0 9:1
8 0:4 1:3 2:4 3:4 4:1 5:0 6:3 7:3 9:0
9 0:0 1:2 2:2 3:2 4:2 5:4 6:0 7:4 8:3

The first column is the vertex label.

Each column after that is an edge from that vertex. The number before the colon is the neighbor and the number after the colon is the edge weight.

It will output to stdout so use redirection to create any files you may need.

If you feel you can make it better, feel free to do so and do a pull request.
