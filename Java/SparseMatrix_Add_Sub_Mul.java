import java.util.Scanner;

class SparseMatrix_Add_Sub_Mul {
    int rows, cols, terms;
    int[][] data;

    // Function to read sparse matrix
    void readMatrix(Scanner sc) {
        System.out.print("Enter number of rows: ");
        rows = sc.nextInt();

        System.out.print("Enter number of columns: ");
        cols = sc.nextInt();

        System.out.print("Enter number of non-zero elements: ");
        terms = sc.nextInt();

        data = new int[terms][3];

        System.out.println("Enter row column value:");
        for (int i = 0; i < terms; i++) {
            data[i][0] = sc.nextInt(); // row
            data[i][1] = sc.nextInt(); // column
            data[i][2] = sc.nextInt(); // value
        }
    }

    // Display sparse matrix
    void display() {
        System.out.println("Row Col Value");
        for (int i = 0; i < terms; i++) {
            System.out.println(data[i][0] + "   " +
                               data[i][1] + "   " +
                               data[i][2]);
        }
    }

    // Convert sparse matrix to normal matrix
    int[][] toNormalMatrix() {
        int[][] mat = new int[rows][cols];

        for (int i = 0; i < terms; i++) {
            mat[data[i][0]][data[i][1]] = data[i][2];
        }

        return mat;
    }

    // Convert normal matrix to sparse matrix and display
    static void displaySparse(int[][] mat, int r, int c) {
        System.out.println("Row Col Value");

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] != 0) {
                    System.out.println(i + "   " + j + "   " + mat[i][j]);
                }
            }
        }
    }

    // Addition
    static void add(SparseMatrix_Add_Sub_Mul s1, SparseMatrix_Add_Sub_Mul s2) {
        if (s1.rows != s2.rows || s1.cols != s2.cols) {
            System.out.println("Addition not possible");
            return;
        }

        int[][] a = s1.toNormalMatrix();
        int[][] b = s2.toNormalMatrix();

        int[][] result = new int[s1.rows][s1.cols];

        for (int i = 0; i < s1.rows; i++) {
            for (int j = 0; j < s1.cols; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }

        System.out.println("Addition Result:");
        displaySparse(result, s1.rows, s1.cols);
    }

    // Subtraction
    static void subtract(SparseMatrix_Add_Sub_Mul s1, SparseMatrix_Add_Sub_Mul s2) {
        if (s1.rows != s2.rows || s1.cols != s2.cols) {
            System.out.println("Subtraction not possible");
            return;
        }

        int[][] a = s1.toNormalMatrix();
        int[][] b = s2.toNormalMatrix();

        int[][] result = new int[s1.rows][s1.cols];

        for (int i = 0; i < s1.rows; i++) {
            for (int j = 0; j < s1.cols; j++) {
                result[i][j] = a[i][j] - b[i][j];
            }
        }

        System.out.println("Subtraction Result:");
        displaySparse(result, s1.rows, s1.cols);
    }

    // Multiplication
    static void multiply(SparseMatrix_Add_Sub_Mul s1, SparseMatrix_Add_Sub_Mul s2) {
        if (s1.cols != s2.rows) {
            System.out.println("Multiplication not possible");
            return;
        }

        int[][] a = s1.toNormalMatrix();
        int[][] b = s2.toNormalMatrix();

        int[][] result = new int[s1.rows][s2.cols];

        for (int i = 0; i < s1.rows; i++) {
            for (int j = 0; j < s2.cols; j++) {
                for (int k = 0; k < s1.cols; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        System.out.println("Multiplication Result:");
        displaySparse(result, s1.rows, s2.cols);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        SparseMatrix_Add_Sub_Mul s1 = new SparseMatrix_Add_Sub_Mul();
        SparseMatrix_Add_Sub_Mul s2 = new SparseMatrix_Add_Sub_Mul();

        System.out.println("Enter First Sparse Matrix");
        s1.readMatrix(sc);

        System.out.println("Enter Second Sparse Matrix");
        s2.readMatrix(sc);

        System.out.println("\nFirst Sparse Matrix:");
        s1.display();

        System.out.println("\nSecond Sparse Matrix:");
        s2.display();

        System.out.println("\n--- Operations ---");

        add(s1, s2);
        subtract(s1, s2);
        multiply(s1, s2);

        sc.close();
    }
}

/*

INPUT: - 

Enter First Sparse Matrix
Enter number of rows: 2
Enter number of columns: 2
Enter number of non-zero elements: 2
Enter row column value:
0 0 5
1 1 8

Enter Second Sparse Matrix
Enter number of rows: 2
Enter number of columns: 2
Enter number of non-zero elements: 2
Enter row column value:
0 1 3
1 0 6

OUTPUT: - 

Addition Result:
Row Col Value
0   0   5
0   1   3
1   0   6
1   1   8

Subtraction Result:
Row Col Value
0   0   5
0   1   -3
1   0   -6
1   1   8

Multiplication Result:
Row Col Value
0   1   15
1   0   48

*/