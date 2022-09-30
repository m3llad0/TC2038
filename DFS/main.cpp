/** 
* 
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < graph.txt
*
**/

#include <iostream>
#include <sstream>
#include "Graph.h"

int main() {
  std::cout << "----- Imprementación de DFS: -----\n";
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph g1(1, inputInfo);
  g1.printGraph();
  // Regresa a linea cero el archivo de entrada
  inputInfo.clear();
  inputInfo.seekg(0);
  // Construye un grafo a partir de la consola usando
  // representacion de Matriz de adyacencia
  Graph g2(2, inputInfo);
  g2.printGraph();
  // Algoritmo DFS iniciando en el nodo 1 del grafo g1
  g1.DFS(1);

} 