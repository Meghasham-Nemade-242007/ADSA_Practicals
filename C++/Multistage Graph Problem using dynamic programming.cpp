// C++ Program to Solve Multistage Graph Problem
// using Dynamic Programming
//
// This program finds the minimum cost path
// from source to destination in a multistage graph.
//
// This program runs perfectly in Dev C++

#include<iostream>
#include<climits>

using namespace std;

#define MAX 10
#define INF 99999

int main()
{
    int n;

    // Input number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[MAX][MAX];

    // Input cost adjacency matrix
    cout << "\nEnter cost adjacency matrix:\n";
    cout << "(Enter 0 if no edge exists)\n\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            // Replace 0 with INF except diagonal
            if(i != j && cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }

    int distance[MAX];
    int path[MAX];

    // Destination vertex cost = 0
    distance[n - 1] = 0;

    // Dynamic Programming
    // Calculate minimum cost from back
    for(int i = n - 2; i >= 0; i--)
    {
        distance[i] = INF;

        for(int j = i + 1; j < n; j++)
        {
            if(cost[i][j] != INF &&
               cost[i][j] + distance[j] < distance[i])
            {
                distance[i] =
                    cost[i][j] + distance[j];

                path[i] = j;
            }
        }
    }

    // Display minimum cost
    cout << "\nMinimum Cost from Source to Destination = "
         << distance[0];

    // Display path
    cout << "\nOptimal Path: ";

    int current = 0;

    cout << current;

    while(current != n - 1)
    {
        current = path[current];
        cout << " -> " << current;
    }

    return 0;
}

/*

===================== SAMPLE OUTPUT =====================

Enter number of vertices: 8

Enter cost adjacency matrix:
(Enter 0 if no edge exists)

0 1 2 5 0 0 0 0
0 0 0 0 4 11 0 0
0 0 0 0 9 5 16 0
0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 18
0 0 0 0 0 0 0 13
0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0

Minimum Cost from Source to Destination = 9

Optimal Path:
0 -> 3 -> 6 -> 7

=========================================================

*/
