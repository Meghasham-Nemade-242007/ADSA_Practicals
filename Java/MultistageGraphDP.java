import java.util.Scanner;

public class MultistageGraphDP {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int n = sc.nextInt();

        int[][] cost = new int[n][n];

        System.out.println("Enter cost adjacency matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = sc.nextInt();
            }
        }

        int[] distance = new int[n];
        int[] path = new int[n];

        // Last vertex distance = 0
        distance[n - 1] = 0;

        // Dynamic Programming from backward
        for (int i = n - 2; i >= 0; i--) {

            distance[i] = Integer.MAX_VALUE;

            for (int j = i + 1; j < n; j++) {

                if (cost[i][j] != 0 &&
                    cost[i][j] + distance[j] < distance[i]) {

                    distance[i] = cost[i][j] + distance[j];

                    path[i] = j;
                }
            }
        }

        System.out.println("\nMinimum Cost = " + distance[0]);

        System.out.print("Path: ");
        int current = 0;

        while (current != n - 1) {
            System.out.print(current + " -> ");
            current = path[current];
        }

        System.out.println(n - 1);

        sc.close();
    }
}

/*
INPUT: - 
Enter number of vertices: 4

Enter cost adjacency matrix:
0 2 5 0
0 0 1 4
0 0 0 2
0 0 0 0

OUTPUT: - 
Minimum Cost = 5
Path: 0 -> 1 -> 2 -> 3
*/