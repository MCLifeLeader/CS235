#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std;

class Edge
{
  public:
   int node;
   int weight;
};
main()
{
   vector< vector<int> > graph;
   vector<Edge> row;
   int i;
   int j;
   int node;
   int adj_node;
   int weight;

   ifstream infile("graph.dat");
   while(!infile.eof())
   {
      infile >> node;
      while (infile >> adj_node >> weight)
      {
         Edge temp;
         temp.node = adj_node;
         temp.weight = weight;
         row.push_back(temp);
      }
   }

   for (i = 0; i < graph.size(); ++i)
   {
      cout << "graph[" << i << "] -> ";
      for (j = 0; j < graph[i].size(); j++)
         cout << graph[i][j].adj_node << ", ";
      cout << endl;
   }
}
