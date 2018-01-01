#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std;

main()
{
   vector< vector<int> > graph;
   vector<int> row;
   int i;
   int j;

   

   // --- nodes adjacent to 1
   row.push_back(2);
   row.push_back(4);
   row.push_back(5);
   graph.push_back(row);
   row.clear();

   // --- nodes adjacent to 2
   row.push_back(3);
   row.push_back(4);
   graph.push_back(row);
   row.clear();

   // --- nodes adjacent to 3
   row.push_back(3);
   graph.push_back(row);
   row.clear();

   // --- nodes adjacent to 4
   row.push_back(2);
   row.push_back(3);
   graph.push_back(row);
   row.clear();

   // --- nodes adjacent to 5
   graph.push_back(row);
   row.clear();
   
   // --- nodes adjacent to 6
   row.push_back(2);
   row.push_back(3);
   graph.push_back(row);
   row.clear();

   // --- print out graph
   for (i = 0; i < graph.size(); ++i)
   {
      cout << "graph[" << i << "] -> ";
      for (j = 0; j < graph[i].size(); j++)
         cout << graph[i][j] << ", ";
      cout << endl;
   }
}
