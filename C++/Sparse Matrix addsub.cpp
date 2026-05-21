// Sparse Matrix Operations using Manual Input in C++
// Operations:
// 1. Addition
// 2. Subtraction
// 3. Multiplication
//
// This program runs perfectly in Dev C++

#include<iostream>
using namespace std;

#define MAX 100

// Structure for Sparse Matrix
struct Sparse
{
    int row;
    int col;
    int value;
};

// Function to display sparse matrix
void display(Sparse s[])
{
    cout << "\nRow\tCol\tValue\n";

    for(int i = 0; i <= s[0].value; i++)
    {
        cout << s[i].row << "\t"
             << s[i].col << "\t"
             << s[i].value << endl;
    }
}

// Function for Addition
void add(Sparse a[], Sparse b[], Sparse result[])
{
    if(a[0].row != b[0].row || a[0].col != b[0].col)
    {
        cout << "\nAddition not possible!";
        return;
    }

    int i=1, j=1, k=1;

    result[0].row = a[0].row;
    result[0].col = a[0].col;

    while(i <= a[0].value && j <= b[0].value)
    {
        if(a[i].row == b[j].row &&
           a[i].col == b[j].col)
        {
            result[k].row = a[i].row;
            result[k].col = a[i].col;
            result[k].value = a[i].value + b[j].value;

            i++;
            j++;
            k++;
        }

        else if(a[i].row < b[j].row ||
               (a[i].row == b[j].row &&
                a[i].col < b[j].col))
        {
            result[k] = a[i];
            i++;
            k++;
        }

        else
        {
            result[k] = b[j];
            j++;
            k++;
        }
    }

    while(i <= a[0].value)
    {
        result[k] = a[i];
        i++;
        k++;
    }

    while(j <= b[0].value)
    {
        result[k] = b[j];
        j++;
        k++;
    }

    result[0].value = k - 1;
}

// Function for Subtraction
void subtract(Sparse a[], Sparse b[], Sparse result[])
{
    Sparse temp[MAX];

    temp[0] = b[0];

    for(int i=1; i<=b[0].value; i++)
    {
        temp[i].row = b[i].row;
        temp[i].col = b[i].col;
        temp[i].value = -b[i].value;
    }

    add(a, temp, result);
}

// Function for Multiplication
void multiply(Sparse a[], Sparse b[], Sparse result[])
{
    if(a[0].col != b[0].row)
    {
        cout << "\nMultiplication not possible!";
        return;
    }

    int matA[20][20] = {0};
    int matB[20][20] = {0};
    int matR[20][20] = {0};

    // Convert sparse to normal matrix
    for(int i=1; i<=a[0].value; i++)
    {
        matA[a[i].row][a[i].col] = a[i].value;
    }

    for(int i=1; i<=b[0].value; i++)
    {
        matB[b[i].row][b[i].col] = b[i].value;
    }

    // Multiplication
    for(int i=0; i<a[0].row; i++)
    {
        for(int j=0; j<b[0].col; j++)
        {
            for(int k=0; k<a[0].col; k++)
            {
                matR[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    // Convert result to sparse matrix
    int x = 1;

    result[0].row = a[0].row;
    result[0].col = b[0].col;

    for(int i=0; i<a[0].row; i++)
    {
        for(int j=0; j<b[0].col; j++)
        {
            if(matR[i][j] != 0)
            {
                result[x].row = i;
                result[x].col = j;
                result[x].value = matR[i][j];
                x++;
            }
        }
    }

    result[0].value = x - 1;
}

// Main Function
int main()
{
    Sparse A[MAX], B[MAX];
    Sparse addResult[MAX], subResult[MAX], mulResult[MAX];

    int nonZero1, nonZero2;

    // First Matrix Input
    cout << "Enter rows, columns and number of non-zero elements for Matrix A: ";
    cin >> A[0].row >> A[0].col >> A[0].value;

    cout << "\nEnter row column value for Matrix A:\n";

    for(int i=1; i<=A[0].value; i++)
    {
        cin >> A[i].row >> A[i].col >> A[i].value;
    }

    // Second Matrix Input
    cout << "\nEnter rows, columns and number of non-zero elements for Matrix B: ";
    cin >> B[0].row >> B[0].col >> B[0].value;

    cout << "\nEnter row column value for Matrix B:\n";

    for(int i=1; i<=B[0].value; i++)
    {
        cin >> B[i].row >> B[i].col >> B[i].value;
    }

    // Display matrices
    cout << "\nFIRST SPARSE MATRIX:";
    display(A);

    cout << "\nSECOND SPARSE MATRIX:";
    display(B);

    // Addition
    add(A, B, addResult);

    cout << "\nADDITION OF SPARSE MATRICES:";
    display(addResult);

    // Subtraction
    subtract(A, B, subResult);

    cout << "\nSUBTRACTION OF SPARSE MATRICES:";
    display(subResult);

    // Multiplication
    multiply(A, B, mulResult);

    cout << "\nMULTIPLICATION OF SPARSE MATRICES:";
    display(mulResult);

    return 0;
}

/*

===================== SAMPLE OUTPUT =====================

Enter rows, columns and number of non-zero elements for Matrix A: 3 3 3

Enter row column value for Matrix A:
0 0 5
1 1 8
2 2 3

Enter rows, columns and number of non-zero elements for Matrix B: 3 3 3

Enter row column value for Matrix B:
0 0 2
1 1 6
2 2 4

FIRST SPARSE MATRIX:

Row     Col     Value
3       3       3
0       0       5
1       1       8
2       2       3

SECOND SPARSE MATRIX:

Row     Col     Value
3       3       3
0       0       2
1       1       6
2       2       4

ADDITION OF SPARSE MATRICES:

Row     Col     Value
3       3       3
0       0       7
1       1       14
2       2       7

SUBTRACTION OF SPARSE MATRICES:

Row     Col     Value
3       3       3
0       0       3
1       1       2
2       2       -1

MULTIPLICATION OF SPARSE MATRICES:

Row     Col     Value
3       3       3
0       0       10
1       1       48
2       2       12

=========================================================

*/
