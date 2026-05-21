import java.util.Scanner;

class BellmanFord {
    static class Edge {
        int source, destination, weight;

        Edge(int s, int d, int w) {
            source = s;
            destination = d;
            weight = w;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int vertices = sc.nextInt();

        System.out.print("Enter number of edges: ");
        int edges = sc.nextInt();

        Edge[] edge = new Edge[edges];

        System.out.println("Enter source destination weight:");
        for (int i = 0; i < edges; i++) {
            int s = sc.nextInt();
            int d = sc.nextInt();
            int w = sc.nextInt();

            edge[i] = new Edge(s, d, w);
        }

        System.out.print("Enter source vertex: ");
        int source = sc.nextInt();

        int[] distance = new int[vertices];

        // Initialize distances
        for (int i = 0; i < vertices; i++) {
            distance[i] = Integer.MAX_VALUE;
        }

        distance[source] = 0;

        // Bellman-Ford Algorithm
        for (int i = 1; i < vertices; i++) {
            for (int j = 0; j < edges; j++) {
                int u = edge[j].source;
                int v = edge[j].destination;
                int w = edge[j].weight;

                if (distance[u] != Integer.MAX_VALUE &&
                    distance[u] + w < distance[v]) {

                    distance[v] = distance[u] + w;
                }
            }
        }

        // Check negative cycle
        boolean negativeCycle = false;

        for (int j = 0; j < edges; j++) {
            int u = edge[j].source;
            int v = edge[j].destination;
            int w = edge[j].weight;

            if (distance[u] != Integer.MAX_VALUE &&
                distance[u] + w < distance[v]) {

                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle) {
            System.out.println("Negative Weight Cycle Exists");
        } else {
            System.out.println("Shortest distances from source vertex " + source);

            for (int i = 0; i < vertices; i++) {
                System.out.println("Vertex " + i + " = " + distance[i]);
            }
        }

        sc.close();
    }
}

/*

INPUT: - 
Enter number of vertices: 5
Enter number of edges: 8

Enter source destination weight:
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

Enter source vertex: 0

OUTPUT: - 
Shortest distances from source vertex 0
Vertex 0 = 0
Vertex 1 = -1
Vertex 2 = 2
Vertex 3 = -2
Vertex 4 = 1

*/