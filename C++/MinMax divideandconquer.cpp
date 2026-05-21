// C++ Program to Find Maximum and Minimum
// using Divide and Conquer Approach
//
// This program runs perfectly in Dev C++

#include<iostream>
using namespace std;

// Function to find Maximum and Minimum
void findMaxMin(int arr[], int low, int high, int &max, int &min)
{
    // If only one element
    if(low == high)
    {
        max = min = arr[low];
    }

    // If two elements
    else if(high == low + 1)
    {
        if(arr[low] > arr[high])
        {
            max = arr[low];
            min = arr[high];
        }
        else
        {
            max = arr[high];
            min = arr[low];
        }
    }

    // More than two elements
    else
    {
        int mid = (low + high) / 2;

        int max1, min1;
        int max2, min2;

        // Divide left part
        findMaxMin(arr, low, mid, max1, min1);

        // Divide right part
        findMaxMin(arr, mid + 1, high, max2, min2);

        // Combine results
        if(max1 > max2)
            max = max1;
        else
            max = max2;

        if(min1 < min2)
            min = min1;
        else
            min = min2;
    }
}

// Main Function
int main()
{
    int n;

    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "\nEnter array elements:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max, min;

    // Function call
    findMaxMin(arr, 0, n - 1, max, min);

    // Output
    cout << "\nMaximum Element = " << max;
    cout << "\nMinimum Element = " << min;

    return 0;
}

/*

===================== SAMPLE OUTPUT =====================

Enter number of elements: 6

Enter array elements:
12 45 7 89 23 5

Maximum Element = 89
Minimum Element = 5

=========================================================

*/
