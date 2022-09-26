/*

BFS algorithm in C++
HW 09 for TC2038.602

*/

#include <iostream>
#include <list>

using namespace std;

class Graph {
    int numVertices;
    list<int>* adj;
    bool* visited;

    public:

    Graph(int vertex);
    void addEgde(int src, int dest);
    void BFS (int startVertex);
};


// Crear un grafo con el numero de vertices dado y una lista de adyacencia
Graph::Graph(int vertex){
    numVertices = vertex;

    adj = new list<int>[vertex];
}

// Agregar los vertices
void Graph::addEgde(int source, int destination){
    adj[source].push_back(destination);
    adj[destination].push_back(source);
}

// BSF algorithm
void Graph::BFS(int startVertex){

    visited = new bool[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currentVertex = queue.front();

        cout << "Visisted: " << currentVertex << " ";
        queue.pop_front();

        for (i = adj[currentVertex].begin(); i != adj[currentVertex].end(); i++)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }   
        }   
    }    
}