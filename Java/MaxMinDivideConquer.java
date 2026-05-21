import java.util.Scanner;

public class MaxMinDivideConquer {

    static int max, min;

    static void findMaxMin(int arr[], int low, int high) {

        // If only one element
        if (low == high) {
            max = min = arr[low];
        }

        // If two elements
        else if (high == low + 1) {

            if (arr[low] > arr[high]) {
                max = arr[low];
                min = arr[high];
            } else {
                max = arr[high];
                min = arr[low];
            }
        }

        // More than two elements
        else {
            int mid = (low + high) / 2;

            findMaxMin(arr, low, mid);
            int max1 = max;
            int min1 = min;

            findMaxMin(arr, mid + 1, high);
            int max2 = max;
            int min2 = min;

            if (max1 > max2)
                max = max1;
            else
                max = max2;

            if (min1 < min2)
                min = min1;
            else
                min = min2;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        findMaxMin(arr, 0, n - 1);

        System.out.println("Maximum element = " + max);
        System.out.println("Minimum element = " + min);

        sc.close();
    }
}

/*
INPUT: - 
Enter number of elements: 6
Enter array elements:
12 45 7 89 23 5

OUTPUT: - 
Maximum element = 89
Minimum element = 5

*/