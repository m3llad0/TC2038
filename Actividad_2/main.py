"""
Actividad integradora 2
Encontrar el camino más corto para realizar cableado

Iwalani Amador
Tonatiuh Reyes
Diego Mellado
"""

import sys

class Graph():
    def __init__(self, vertex):
        self.solutionList = []
        self.V = vertex
        self.graph = [[0 for column in range(vertex)]
                        for row in range(vertex)]
    
    def solution(self, distance):
        print("Vertex \tDistance from source")
        for node in range(self.V):
            node_ = [str(node+1), distance[node]]
            self.solutionList.append(node_)
        
        print(sorted(self.solutionList))

    def minimumDistance(self, distance, shortestPath):
        
        min = sys.maxsize

        for u in range(self.V):
            if distance[u] < min and shortestPath[u] == False:
                min = distance[u]
                min_index = u

        return min_index

    def Dijkstra(self, source):
        
        distance = [sys.maxsize] * self.V
        distance[source-1] = 0
        shortestPath = [False] * self.V

        for cout in range(self.V):

            x = self.minimumDistance(distance, shortestPath)

            shortestPath[x] = True

            for y in range(self.V):
                 if self.graph[x][y] > 0 and shortestPath[y] == False and \
                        distance[y] > distance[x] + self.graph[x][y]:
                    distance[y] = distance[x] + self.graph[x][y]
            
        self.solution(distance)

def main():
    graph = Graph(4)
    graph.graph = [[0, 16, 45, 32],
                   [16, 0, 18, 21],
                   [45, 18, 0,  7],
                   [32, 21, 7,  0]]
 
    graph.Dijkstra(4)

main()


