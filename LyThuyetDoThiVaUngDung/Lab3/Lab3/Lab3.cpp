#include<iostream>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
const int MAX = 100;
struct Edge {
    int u, v, w;
};
struct Graph {
    int sodinh, a[MAX][MAX];
    Edge T[MAX];
    int sumT;
};
struct Queue
{
    int q[100];
    int size = 0;
    int front = 0;
    int pos = 0;
    bool Empty() {
        return size == 0;
    }
    void Push(int value) {
        q[pos++] = value;
        size++;
    }
    int Front() {
        if (Empty()) {
            cout << "Queue rong!";
            return -1;
        }
        else {
            size--;
            int value = q[front];
            front++;
            return value;
        }

    }
};

void readGraph(string fn, Graph& x) {
    ifstream fs(fn);
    if (fs.is_open()) {
        fs >> x.sodinh;
        for (int i = 0; i < x.sodinh; i++) {
            for (int j = 0; j < x.sodinh; j++) {
                fs >> x.a[i][j];
            }
        }
        fs.close();
    }
    else
        cout << "Khong mo dc file!!";
}
int visited[MAX] = { 0 };
Edge findMinEdge(Edge arr[], int n) {
    Edge canhnhonhat = arr[0];
    for (int j = 1; j < n; j++) {
        if (canhnhonhat.w > arr[j].w) {
            canhnhonhat = arr[j];
        }
    }
    return canhnhonhat;
}
void Prim(Graph& x) {
    visited[0] = 1;
    int nT = 0;
    while (nT < x.sodinh - 1) {
        Edge arr[MAX];
        int n = 0;
        for (int i = 0; i < x.sodinh; i++) {
            if (visited[i] == 0) {
                for (int j = 0; j < x.sodinh; j++) {
                    if (visited[j] == 1 && x.a[i][j] != 0) {
                        Edge e = { i, j, x.a[i][j] };
                        arr[n] = e;
                        n++;
                    }
                }
            }
        }
        x.T[nT++] = findMinEdge(arr, n);;
        visited[findMinEdge(arr, n).u] = 1;
    }
    x.sumT = 0;
    for (int i = 0; i < nT; i++) {
        x.sumT += x.T[i].w;
    }
}
void printSpanningTree(Graph x) {
    cout << x.sumT << endl;
    for (int i = 0; i < x.sodinh - 1; i++) {
        cout << x.T[i].v + 1 << " " << x.T[i].u + 1 << endl;
    }
}
int main() {
    Graph x;
    readGraph("dothi.txt", x);
    Prim(x);
    printSpanningTree(x);
}