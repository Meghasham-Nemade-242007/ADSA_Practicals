// C++ Program for N-Queens Problem
// using Backtracking
//
// This program places N queens on an N x N chessboard
// such that no two queens attack each other.
//
// This program runs perfectly in Dev C++

#include<iostream>

using namespace std;

#define MAX 20

int board[MAX][MAX];
int n;

// Function to check if queen can be placed
bool isSafe(int row, int col)
{
    int i, j;

    // Check left side of current row
    for(i = 0; i < col; i++)
    {
        if(board[row][i] == 1)
        {
            return false;
        }
    }

    // Check upper diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    // Check lower diagonal
    for(i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N-Queens
bool solveNQueen(int col)
{
    // All queens placed
    if(col >= n)
    {
        return true;
    }

    // Try placing queen in each row
    for(int i = 0; i < n; i++)
    {
        if(isSafe(i, col))
        {
            // Place queen
            board[i][col] = 1;

            // Recursive call
            if(solveNQueen(col + 1))
            {
                return true;
            }

            // Backtracking
            board[i][col] = 0;
        }
    }

    return false;
}

// Function to display solution
void displayBoard()
{
    cout << "\nSolution Board:\n\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }

        cout << endl;
    }
}

// Main Function
int main()
{
    // Input number of queens
    cout << "Enter value of N: ";
    cin >> n;

    // Initialize board
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    // Solve N-Queens
    if(solveNQueen(0))
    {
        displayBoard();
    }
    else
    {
        cout << "\nSolution does not exist!";
    }

    return 0;
}

/*

===================== SAMPLE OUTPUT =====================

Enter value of N: 4

Solution Board:

. . Q .
Q . . .
. . . Q
. Q . .

=========================================================

*/
