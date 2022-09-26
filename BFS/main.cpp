/*

HW 09
BFS algorithm implementation
Diego Mellado A01655451
Iwalani Amador A01732251
Tonatiuh Reyes A01025459.

*/
#include "graph.hpp"

int main(){

   Graph g(6);
   g.addEgde(1, 2);
   g.addEgde(1, 4);
   g.addEgde(2, 3);
   g.addEgde(3, 5);
   g.addEgde(4, 2);
   g.addEgde(5, 4);

  g.BFS(2);

  return 0;

}