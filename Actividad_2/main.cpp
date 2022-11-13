/*
Actividad integradora 2

Tonatiu
Iwalani
Diego
*/

#include <iostream>
#include <climits>

using namespace std;
int miniumDistance(int distance[], bool Tset[], int size){
    
    int min = INT16_MAX, index;

    for (int i = 0; i < size; i++)
    {
        if (Tset[i] == false && distance[i] <= min)
        {
            min = distance[i];
            index = i;
        }
        
    }

    return index;
}

void Dijkstra(int i, int graph[4][4], int src){

    int distance[i];
    bool Tset[i];

    for (int i = 0; i < i; i++)
    {
        distance[i] = INT_MAX;
        Tset[i] = false;
    }
    
    distance[src] = 0;

    for (int i = 0; i < i; i++)
    {
        int m = miniumDistance(distance, Tset, i);
        Tset[m] = true;

        for (int i = 0; i < i; i++)
        {
            if(!Tset[i] && graph[m][i] && distance[m]!=INT_MAX && distance[m]+graph[m][i] < distance[i])
				distance[i] = distance[m] + graph[m][i];
            
        }  
    }

	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<6; i++)                      
	{ //Printing
		char str=65+i; // Ascii values for pritning A,B,C..
		cout<< str << "\t\t\t" << distance[i] << endl;
	}
    
}

int main(){
    
    int graph[4][4] = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };


    Dijkstra(4, graph, 4);
}