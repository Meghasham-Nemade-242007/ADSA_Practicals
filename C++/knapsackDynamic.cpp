// C++ Program for 0/1 Knapsack Problem using Dynamic Programming
//
// Problem:
// Find maximum profit without exceeding knapsack capacity.
//
// This program runs perfectly in Dev C++

#include<iostream>
using namespace std;

int main()
{
    int n;

    // Input number of items
    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], profit[n];

    // Input weights
    cout << "\nEnter weights of items:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    // Input profits
    cout << "\nEnter profits of items:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    int capacity;

    // Input knapsack capacity
    cout << "\nEnter knapsack capacity: ";
    cin >> capacity;

    // DP Table
    int dp[n + 1][capacity + 1];

    // Build table
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            // Base Condition
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            // If current item weight <= capacity
            else if(weight[i - 1] <= w)
            {
                int include =
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                int exclude =
                    dp[i - 1][w];

                // Take maximum
                if(include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }

            // If item cannot be included
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display DP Table
    cout << "\nDynamic Programming Table:\n\n";

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            cout << dp[i][w] << "\t";
        }

        cout << endl;
    }

    // Final Answer
    cout << "\nMaximum Profit = "
         << dp[n][capacity];

    return 0;
}

/*

===================== SAMPLE OUTPUT =====================

Enter number of items: 4

Enter weights of items:
1 3 4 5

Enter profits of items:
1 4 5 7

Enter knapsack capacity: 7

Dynamic Programming Table:

0       0       0       0       0       0       0       0
0       1       1       1       1       1       1       1
0       1       1       4       5       5       5       5
0       1       1       4       5       6       6       9
0       1       1       4       5       7       8       9

Maximum Profit = 9

=========================================================

*/
