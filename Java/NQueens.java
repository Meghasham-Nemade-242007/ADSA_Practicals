import java.util.Scanner;

public class NQueens {

    static int N;
    static int[] board;

    // Check safe position
    static boolean isSafe(int row, int col) {

        for (int i = 0; i < row; i++) {

            // Same column or diagonal
            if (board[i] == col ||
                Math.abs(board[i] - col) == Math.abs(i - row)) {
                return false;
            }
        }

        return true;
    }

    // Solve using backtracking
    static boolean solve(int row) {

        if (row == N) {
            return true;
        }

        for (int col = 0; col < N; col++) {

            if (isSafe(row, col)) {

                board[row] = col;

                if (solve(row + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    // Display board
    static void display() {

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {

                if (board[i] == j)
                    System.out.print("Q ");
                else
                    System.out.print(". ");
            }

            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of queens: ");
        N = sc.nextInt();

        board = new int[N];

        if (solve(0)) {

            System.out.println("\nSolution:");
            display();

        } else {
            System.out.println("No solution exists");
        }

        sc.close();
    }
}

/*
INPUT:-
Enter number of queens: 4

OUTPUT: - 
Solution:
. Q . .
. . . Q
Q . . .
. . Q .
*/