/*

HW 09
BFS algorithm implementation
Diego Mellado A01655451
Iwalani Amador A01732251
Tonatiuh Reyes A01025459.

*/
#include "graph.hpp"

int main(){

   Graph g(4);
   g.addEdge(1, 2);
   g.addEdge(1, 4);
   g.addEdge(2, 3);
   g.addEdge(3, 5);
   g.addEdge(4, 2);
   g.addEdge(5, 4);

  g.BFS(2);

  return 0;

}