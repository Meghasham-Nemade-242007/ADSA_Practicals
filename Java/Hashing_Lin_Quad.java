import java.util.Scanner;

class Hashing_Lin_Quad {
    int[] hashTable;
    int size;

    Hashing_Lin_Quad(int size) {
        this.size = size;
        hashTable = new int[size];

        // Initialize all positions with -1
        for (int i = 0; i < size; i++) {
            hashTable[i] = -1;
        }
    }

    // Display Hash Table
    void display() {
        System.out.println("Index\tValue");
        for (int i = 0; i < size; i++) {
            System.out.println(i + "\t" + hashTable[i]);
        }
    }

    // Linear Probing
    void linearProbingInsert(int key) {
        int index = key % size;

        while (hashTable[index] != -1) {
            index = (index + 1) % size;
        }

        hashTable[index] = key;
    }

    // Quadratic Probing
    void quadraticProbingInsert(int key) {
        int index = key % size;
        int i = 1;

        while (hashTable[index] != -1) {
            index = (key % size + i * i) % size;
            i++;
        }

        hashTable[index] = key;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of hash table: ");
        int size = sc.nextInt();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] elements = new int[n];

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            elements[i] = sc.nextInt();
        }

        // Linear Probing
        Hashing_Lin_Quad linear = new Hashing_Lin_Quad(size);

        for (int i = 0; i < n; i++) {
            linear.linearProbingInsert(elements[i]);
        }

        System.out.println("\nHash Table using Linear Probing:");
        linear.display();

        // Quadratic Probing
        Hashing_Lin_Quad quadratic = new Hashing_Lin_Quad(size);

        for (int i = 0; i < n; i++) {
            quadratic.quadraticProbingInsert(elements[i]);
        }

        System.out.println("\nHash Table using Quadratic Probing:");
        quadratic.display();

        sc.close();
    }
}

/*

INPUT: -
Enter size of hash table: 10
Enter number of elements: 5
Enter elements:
12 22 32 25 35

OUTPUT: - 
Hash Table using Linear Probing:

Index   Value
0       -1
1       -1
2       12
3       22
4       32
5       25
6       35
7       -1
8       -1
9       -1

Hash Table using Quadratic Probing:

Index   Value
0       -1
1       -1
2       12
3       22
4       35
5       25
6       32
7       -1
8       -1
9       -1

*/