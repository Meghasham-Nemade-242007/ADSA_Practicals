// C++ Program to Implement:
// 1. Linear Probing
// 2. Quadratic Probing
//
// This program runs perfectly in Dev C++

#include<iostream>
using namespace std;

#define SIZE 10

// Hash Table Arrays
int linearTable[SIZE];
int quadraticTable[SIZE];

// Function to initialize tables
void initialize()
{
    for(int i = 0; i < SIZE; i++)
    {
        linearTable[i] = -1;
        quadraticTable[i] = -1;
    }
}

// Hash Function
int hashFunction(int key)
{
    return key % SIZE;
}

// ---------------- LINEAR PROBING ----------------

// Function to insert using Linear Probing
void insertLinear(int key)
{
    int index = hashFunction(key);
    int original = index;

    while(linearTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        // Table Full
        if(index == original)
        {
            cout << "\nLinear Hash Table is Full!";
            return;
        }
    }

    linearTable[index] = key;
}

// Function to display Linear Table
void displayLinear()
{
    cout << "\nLINEAR PROBING HASH TABLE\n";

    cout << "\nIndex\tValue\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";

        if(linearTable[i] != -1)
            cout << linearTable[i];
        else
            cout << "EMPTY";

        cout << endl;
    }
}

// ---------------- QUADRATIC PROBING ----------------

// Function to insert using Quadratic Probing
void insertQuadratic(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while(quadraticTable[(index + i*i) % SIZE] != -1)
    {
        i++;

        // Table Full Check
        if(i == SIZE)
        {
            cout << "\nQuadratic Hash Table is Full!";
            return;
        }
    }

    quadraticTable[(index + i*i) % SIZE] = key;
}

// Function to display Quadratic Table
void displayQuadratic()
{
    cout << "\nQUADRATIC PROBING HASH TABLE\n";

    cout << "\nIndex\tValue\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";

        if(quadraticTable[i] != -1)
            cout << quadraticTable[i];
        else
            cout << "EMPTY";

        cout << endl;
    }
}

// ---------------- MAIN FUNCTION ----------------

int main()
{
    int n, key;

    initialize();

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "\nEnter elements:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> key;

        insertLinear(key);
        insertQuadratic(key);
    }

    // Display Tables
    displayLinear();

    displayQuadratic();

    return 0;
}

/*

==================== SAMPLE OUTPUT ====================

Enter number of elements: 6

Enter elements:
23
43
13
27
33
53

LINEAR PROBING HASH TABLE

Index   Value
0       EMPTY
1       EMPTY
2       EMPTY
3       23
4       43
5       13
6       33
7       27
8       53
9       EMPTY

QUADRATIC PROBING HASH TABLE

Index   Value
0       EMPTY
1       EMPTY
2       EMPTY
3       23
4       43
5       13
6       53
7       27
8       33
9       EMPTY

======================================================

*/
