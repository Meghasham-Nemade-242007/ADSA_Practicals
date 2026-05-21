import java.util.Scanner;

public class TSPBranchBound {

    static int N;
    static int[][] cost;
    static boolean[] visited;

    static int finalCost = Integer.MAX_VALUE;

    // Function to solve TSP
    static void tsp(int currentCity, int count, int currentCost) {

        // If all cities visited and return path exists
        if (count == N && cost[currentCity][0] > 0) {

            int totalCost = currentCost + cost[currentCity][0];

            if (totalCost < finalCost) {
                finalCost = totalCost;
            }
            return;
        }

        // Visit next city
        for (int i = 0; i < N; i++) {

            if (!visited[i] && cost[currentCity][i] > 0) {

                visited[i] = true;

                tsp(i, count + 1,
                        currentCost + cost[currentCity][i]);

                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of cities: ");
        N = sc.nextInt();

        cost = new int[N][N];
        visited = new boolean[N];

        System.out.println("Enter cost matrix:");

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cost[i][j] = sc.nextInt();
            }
        }

        visited[0] = true;

        tsp(0, 1, 0);

        System.out.println("Minimum travelling cost = " + finalCost);

        sc.close();
    }
}

/*
INPUT: - 
Enter number of cities: 4

Enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

OUTPUT: - 

Minimum travelling cost = 80
*/