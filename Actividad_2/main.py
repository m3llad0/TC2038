"""
Actividad integradora 2
Encontrar el camino más corto para realizar cableado

Iwalani Amador
Tonatiuh Reyes
Diego Mellado
"""

from collections import defaultdict
import heapq

class Graph():
    """
    Clase que representa un grafo
    ELements:
        path: Lista que contiene el camino más corto
        V: Numero de vertices
        adjList: Lista de adyacencia (Grafo)
    """
    def __init__(self, vertex, matrix):
        """
        Constructor de la clase
        Args:
            vertex: Numero de vertices
            matrix: Matriz de adyacencia
        """
        self.path = []
        self.V = vertex
        # Matrix to adjacency list. We see it faster and easier to work with
        self.adjList = defaultdict(list)
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                        if matrix[i][j] != 0:
                            self.adjList[i].append([j, matrix[i][j]])

    def solution(self, start):
        self.path.append(start)
        for i in range(self.V-1):
            dist = self.dijkstra(self.path[i])
            smallest = None
            for j in range(self.V):
                if dist[j] != 0 and dist[j] != float('inf') and j not in self.path:
                    if smallest == None:
                        smallest = dist[j]
                    elif smallest > dist[j]:
                        smallest = dist[j]
            if smallest == None:
                self.path.append(dist.index(float('inf')))
            else:
                self.path.append(dist.index(smallest))

        return self.path

    def dijkstra(self, source):
        dist = [float('inf')] * self.V
        seen = set()
        heap = []
        dist[source] = 0

        heapq.heappush(heap, (source, dist[source]))

        while len(heap) > 0:
            node, weight = heapq.heappop(heap)
            seen.add(weight)
            for conn, w in self.adjList[node]:
                if conn not in seen:
                    d = weight + w
                    if d < dist[conn]:
                        dist[conn] = d
                        heapq.heappush(heap, (conn, d))
        return dist

def read_file():
    with open("input.txt", "r") as file:
        start = int(file.readline())
        matrix = []
        for line in file:
            matrix.append([int(x) for x in line.split(",")])
        return start, matrix

def main():
    # Txt format should be:
    # 1st line: Start node (int) If you want first node start at 0. Ends at newline
    # Next lines: Matrix of adyacence, each element in a row separated by a coma, and rows separated newline.
    # Example:
    # 0
    # 0, 16, 45, 32
    # 16, 0, 18, 21
    # 45, 18, 0,  7
    # 32, 21, 7,  0

    start, matrix = read_file()

    graph = Graph(len(matrix), matrix)

    solution = graph.solution(start)

    print(" Forma de cablear las colonias con fibra: (", end=" ")
    abc = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    for i in range(len(solution)):
        print(abc[solution[i]], end=", ")
    print(")")


main()


