#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct Edge {
    int u, v, w;
};

struct Graph {
    int Nv, Ne;

    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<Edge> T;

    Graph() : Nv(0), Ne(0) {}

    void init_Graph() {
        adj.resize(Nv, vector<int>(Nv, 0));
    }

    void add_Edge(int u, int v, int w) {
        edges.push_back({ u, v, w });
        Ne++;
    }
};

void Read_Graph(string fn, Graph& graph) {
    ifstream ifile(fn);
    if (!ifile.is_open()) {
        cout << "Khong mo duoc file\n";
        return;
    }

    ifile >> graph.Nv;
    graph.init_Graph();

    for (int i = 0; i < graph.Nv; i++) {
        for (int j = 0; j < graph.Nv; j++) {
            ifile >> graph.adj[i][j];
            if (i < j && graph.adj[i][j] != 0) {
                graph.add_Edge(i, j, graph.adj[i][j]);
            }
        }
    }
}

int Sum_T(vector<Edge> e) {
    int total_W = 0;
    for (const Edge& edge : e) {
        total_W += edge.w;
    }
    return total_W;
}

void Edges_in_Graph(vector<Edge> e, ostream& ofile) {
    for (Edge edge : e) {
        ofile << "(" << edge.u << "," << edge.v << ")" << "\n\n";
    }
}

int find(vector<int>& parent, int u) {
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void Union_Sets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        }
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void Bubble_Sort_Edge(vector<Edge>& edges) {
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                swap(edges[j], edges[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void Kruskal(int& Nv, vector<Edge>& edges, vector<Edge>& T) {
    vector<int> parent(Nv);
    vector<int> rank(Nv, 0);

    for (int i = 0; i < Nv; i++) {
        parent[i] = i;
    }

    Bubble_Sort_Edge(edges);

    int edges_In_MST = 0;
    for (Edge e : edges) {
        if (find(parent, e.u) != find(parent, e.v)) {
            T.push_back(e);
            Union_Sets(parent, rank, e.u, e.v);
            edges_In_MST++;
            if (edges_In_MST == Nv - 1) break;
        }
    }
}

void Print_Spinning_Matrix(ofstream& os, Graph graph) {
    os << "Tong trong so trong do thi cay nho nhat la : " << Sum_T(graph.T) << "\n";
    Edges_in_Graph(graph.T, os);

    os << "Do thi cay khung nho nhat co ma tran la:\n";

    vector<vector<int>> spanning_Matrix(graph.Nv, vector<int>(graph.Nv, 0));

    for (const auto& edge : graph.T) {
        spanning_Matrix[edge.u][edge.v] = edge.w;
        spanning_Matrix[edge.v][edge.u] = edge.w;
    }

    for (int i = 0; i < graph.Nv; i++) {
        for (int j = 0; j < graph.Nv; j++) {
            os << setw(4) << spanning_Matrix[i][j];
        }
        os << "\n";
    }
}

int main() {
    Graph graph;
    Read_Graph("dothi.txt", graph);

    Kruskal(graph.Nv, graph.edges, graph.T);

    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {

        Print_Spinning_Matrix(outputFile, graph);

        outputFile.close();
    }
    else {
        cout << "Khong mo duoc file de ghi ket qua\n";
    }

    return 0;
}

