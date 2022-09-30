#include "Graph.h"

void Graph::BFS(int v) {
  // Declaramos un set del STL de C++ (elementos unicos y ordenados)
  std::set<int> visited;
  // Creamos una queue 
  QueueLinkedList<int> queue;
  // Marcamos el vertice actual v como visitado y entra al queue
  visited.insert(v);
  queue.enqueue(v);
  std::cout << "Recorrido BFS " << std::endl;
  while(!queue.isEmpty()) {
    // Extraemos un vertice del queue y lo procesamos (print) 
    v = queue.dequeue();
    std::cout << v << " ";
    // Obtenemos los vertices adyacentes del vertice v
    // Si estos no han sido visitados entonces se marcan como visitados
    // y los metemos al queue
    if (representation == 1) { // Lista de adyacencia
      // Recorrer nodos adyacentes de v
      for (int j = 0; j < (int)adjList[v].getNumElements(); j ++) {
        int u = adjList[v].getData(j);
        // Verifica si u ya fue visitado en tiempo O(log n)
        bool isInVisited = visited.find(u) != visited.end();
        if (!isInVisited) {
          visited.insert(u);
          queue.enqueue(u);
        }
      }
    }
    else { // Matriz de adyacencia
      // Recorrer nodos adyacentes a v
      for (int u = 1; u <= numNodes; u++) {
        int c = adjMatrix[v][u];
        if (c != 0) {
          // Verifica si u ya fue visitado en tiempo O(log n)
          bool isInVisited = visited.find(u) != visited.end();
          if (!isInVisited) {
            visited.insert(u);
            queue.enqueue(u);
          }
        }
      }
    }
  }
  std::cout << std::endl;
}
