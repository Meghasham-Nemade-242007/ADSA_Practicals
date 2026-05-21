// C++ Program for Bellman-Ford Algorithm
// Finds shortest path from source vertex to all other vertices
//
// Bellman-Ford works for:
// 1. Weighted Graph
// 2. Negative Edge Weights
// 3. Detects Negative Weight Cycle
//
// This program runs perfectly in Dev C++

#include<iostream>
using namespace std;

#define INF 99999

// Structure to store edge
struct Edge
{
    int src;
    int dest;
    int weight;
};

int main()
{
    int V, E;

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[E];

    // Input edges
    cout << "\nEnter source destination weight:\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].src
            >> edges[i].dest
            >> edges[i].weight;
    }

    int source;

    // Input source vertex
    cout << "\nEnter source vertex: ";
    cin >> source;

    // Distance array
    int dist[V];

    // Initialize distances
    for(int i = 0; i < V; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    // Bellman-Ford Algorithm
    // Relax all edges V-1 times

    for(int i = 1; i <= V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            // Relaxation Condition
            if(dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for Negative Weight Cycle
    bool negativeCycle = false;

    for(int j = 0; j < E; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if(dist[u] != INF && dist[u] + w < dist[v])
        {
            negativeCycle = true;
            break;
        }
    }

    // Output
    if(negativeCycle)
    {
        cout << "\nGraph contains Negative Weight Cycle!";
    }
    else
    {
        cout << "\nShortest distances from Source Vertex "
             << source << ":\n";

        cout << "\nVertex\tDistance\n";

        for(int i = 0; i < V; i++)
        {
            cout << i << "\t";

            if(dist[i] == INF)
                cout << "INF";
            else
                cout << dist[i];

            cout << endl;
        }
    }

    return 0;
}

/*

===================== SAMPLE OUTPUT =====================

Enter number of vertices: 5
Enter number of edges: 8

Enter source destination weight:
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

Enter source vertex: 0

Shortest distances from Source Vertex 0:

Vertex Distance
0       0
1       -1
2       2
3       -2
4       1

=========================================================

*/
