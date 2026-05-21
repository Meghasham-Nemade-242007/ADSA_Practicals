// C++ Program for Traveling Salesman Problem (TSP)
// using Branch and Bound Technique
//
// This program finds the minimum cost path
// that visits all cities exactly once
// and returns to the starting city.
//
// This program runs perfectly in Dev C++

#include<iostream>
#include<climits>

using namespace std;

#define MAX 10

int n;                          // Number of cities
int cost[MAX][MAX];             // Cost matrix

int visited[MAX];               // Visited cities
int finalPath[MAX];             // Stores best path

int finalCost = INT_MAX;        // Minimum cost

// Function to copy path
void copyPath(int currentPath[])
{
    for(int i = 0; i < n; i++)
    {
        finalPath[i] = currentPath[i];
    }

    finalPath[n] = currentPath[0];
}

// Function to calculate lower bound
int firstMin(int i)
{
    int min = INT_MAX;

    for(int k = 0; k < n; k++)
    {
        if(cost[i][k] < min && i != k)
        {
            min = cost[i][k];
        }
    }

    return min;
}

// Function to calculate second minimum
int secondMin(int i)
{
    int first = INT_MAX, second = INT_MAX;

    for(int j = 0; j < n; j++)
    {
        if(i == j)
            continue;

        if(cost[i][j] <= first)
        {
            second = first;
            first = cost[i][j];
        }
        else if(cost[i][j] < second &&
                cost[i][j] != first)
        {
            second = cost[i][j];
        }
    }

    return second;
}

// Branch and Bound Recursive Function
void TSP(int currentBound,
         int currentWeight,
         int level,
         int currentPath[])
{
    // If all cities are visited
    if(level == n)
    {
        // Check return path to source
        if(cost[currentPath[level - 1]][currentPath[0]] != 0)
        {
            int currentResult =
                currentWeight +
                cost[currentPath[level - 1]][currentPath[0]];

            // Update minimum cost
            if(currentResult < finalCost)
            {
                copyPath(currentPath);
                finalCost = currentResult;
            }
        }

        return;
    }

    // Try all cities
    for(int i = 0; i < n; i++)
    {
        if(cost[currentPath[level - 1]][i] != 0 &&
           visited[i] == 0)
        {
            int temp = currentBound;

            currentWeight +=
                cost[currentPath[level - 1]][i];

            // Calculate new bound
            if(level == 1)
            {
                currentBound -=
                    ((firstMin(currentPath[level - 1]) +
                      firstMin(i)) / 2);
            }
            else
            {
                currentBound -=
                    ((secondMin(currentPath[level - 1]) +
                      firstMin(i)) / 2);
            }

            // Check promising node
            if(currentBound + currentWeight < finalCost)
            {
                currentPath[level] = i;
                visited[i] = 1;

                TSP(currentBound,
                    currentWeight,
                    level + 1,
                    currentPath);
            }

            // Backtrack
            currentWeight -=
                cost[currentPath[level - 1]][i];

            currentBound = temp;

            for(int j = 0; j < n; j++)
            {
                visited[j] = 0;
            }

            for(int j = 0; j < level; j++)
            {
                visited[currentPath[j]] = 1;
            }
        }
    }
}

// Function to solve TSP
void solveTSP()
{
    int currentPath[MAX + 1];

    int currentBound = 0;

    // Compute initial bound
    for(int i = 0; i < n; i++)
    {
        currentBound +=
            (firstMin(i) + secondMin(i));
    }

    // Round off
    if(currentBound % 2 == 1)
        currentBound = currentBound / 2 + 1;
    else
        currentBound = currentBound / 2;

    // Initialize visited array
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[0] = 1;

    currentPath[0] = 0;

    // Start TSP from city 0
    TSP(currentBound, 0, 1, currentPath);
}

// Main Function
int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "\nEnter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    solveTSP();

    // Display Result
    cout << "\nMinimum Cost = "
         << finalCost;

    cout << "\nOptimal Path: ";

    for(int i = 0; i <= n; i++)
    {
        cout << finalPath[i];

        if(i != n)
            cout << " -> ";
    }

    return 0;
}

/*

===================== SAMPLE OUTPUT =====================

Enter number of cities: 4

Enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Minimum Cost = 80

Optimal Path:
0 -> 1 -> 3 -> 2 -> 0

=========================================================

*/
