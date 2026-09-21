#include <iostream>
#include <fstream>
#include <limits.h>  // For INT_MAX
using namespace std;

const int Max = 100;
const int INF = INT_MAX;

struct Graph {
    int sodinh, socanh;  // sodinh = number of vertices, socanh = number of edges
    int u[Max], v[Max], weight[Max];  // Arrays for storing edges and their weights
};

void readgraph(Graph& g, string fn) {
    ifstream f(fn);
    if (f.is_open()) {
        f >> g.sodinh;  // Read the number of vertices
        g.socanh = 0;  // Initialize number of edges to 0

        int adjMatrix[Max][Max];  // Temporary matrix to store the input

        // Read the adjacency matrix
        for (int i = 0; i < g.sodinh; i++) {
            for (int j = 0; j < g.sodinh; j++) {
                f >> adjMatrix[i][j];
            }
        }

        // Convert the adjacency matrix to an edge list
        for (int i = 0; i < g.sodinh; i++) {
            for (int j = 0; j < g.sodinh; j++) {
                if (adjMatrix[i][j] != 0) {  // If there's an edge, add it to the edge list
                    g.u[g.socanh] = i;  // Start vertex
                    g.v[g.socanh] = j;  // End vertex
                    g.weight[g.socanh] = adjMatrix[i][j];  // Weight of the edge
                    g.socanh++;  // Increment the edge count
                }
            }
        }
        f.close();
    }
    else {
        cout << "Cannot open file" << endl;
    }
}

void BellmanFord(Graph g, int src, string fn) {
    int dist[Max];  // Array to store the distance from the source
    int parent[Max];  // Array to store the parent of each vertex in the path

    // Initialize distances
    for (int i = 0; i < g.sodinh; i++) {
        dist[i] = INF;
        parent[i] = -1;  // No parent initially
    }
    dist[src] = 0;  // Distance from source to itself is 0

    // Relax all edges |V| - 1 times
    for (int i = 0; i < g.sodinh - 1; i++) {
        for (int j = 0; j < g.socanh; j++) {
            int u = g.u[j];
            int v = g.v[j];
            int weight = g.weight[j];
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < g.socanh; i++) {
        int u = g.u[i];
        int v = g.v[i];
        int weight = g.weight[i];
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    // Write results to file
    ofstream f(fn);
    if (f.is_open()) {
        f << "Vertex   Distance from Source" << endl;
        for (int i = 0; i < g.sodinh; i++) {
            f << i << "\t\t";
            if (dist[i] == INF)
                f << "INF" << endl;  // If distance is INF, print INF
            else
                f << dist[i] << endl;  // Else, print the distance value
        }
        f.close();
    }
}

int main() {
    Graph g;
    readgraph(g, "dothi.txt");  // Reading the graph from file "dothi.txt"
    BellmanFord(g, 0, "output.txt");  // Start Bellman-Ford from vertex 0 and output to "output.txt"
    return 0;
}
