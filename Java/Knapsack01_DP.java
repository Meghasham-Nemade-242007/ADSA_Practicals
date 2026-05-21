import java.util.Scanner;

public class Knapsack01_DP {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        int[] weight = new int[n + 1];
        int[] profit = new int[n + 1];

        System.out.println("Enter weights:");
        for (int i = 1; i <= n; i++) {
            weight[i] = sc.nextInt();
        }

        System.out.println("Enter profits:");
        for (int i = 1; i <= n; i++) {
            profit[i] = sc.nextInt();
        }

        System.out.print("Enter knapsack capacity: ");
        int capacity = sc.nextInt();

        int[][] dp = new int[n + 1][capacity + 1];

        // Dynamic Programming
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= capacity; w++) {

                if (weight[i] <= w) {
                    dp[i][w] = Math.max(
                            profit[i] + dp[i - 1][w - weight[i]],
                            dp[i - 1][w]
                    );
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        // Display DP Table
        System.out.println("\nDP Table:");
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                System.out.print(dp[i][w] + "\t");
            }
            System.out.println();
        }

        System.out.println("\nMaximum Profit = " + dp[n][capacity]);

        sc.close();
    }
}

/*
INPUT: - 
Enter number of items: 4

Enter weights:
2 1 3 2

Enter profits:
12 10 20 15

Enter knapsack capacity: 5

OUTPUT: - 
DP Table:

0	0	0	0	0	0
0	0	12	12	12	12
0	10	12	22	22	22
0	10	12	22	30	32
0	10	15	25	30	37

Maximum Profit = 37

*/