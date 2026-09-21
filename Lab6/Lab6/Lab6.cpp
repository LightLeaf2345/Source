#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int Max = 100;
const int vocuc = 100;

struct Graph {
    int sodinh;
    int a[Max][Max];
};

bool ThuocT[Max];
int LastV[Max];

void readgraph(Graph& g, string fn) {
    ifstream f;
    f.open(fn);
    if (f.is_open()) {
        f >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++)
            for (int j = 0; j < g.sodinh; j++)
                f >> g.a[i][j];
        f.close();
    }
    else {
        cout << "Cant file";
    }
}
int L[Max][Max];
int P[Max][Max];

void Floy(Graph g) {
    for (int i = 0; i < g.sodinh; i++) {
        for (int j = 0; j < g.sodinh; j++) {
            P[i][j] = i;
            L[i][j] = g.a[i][j];
        }
    }
    for (int k = 0; k < g.sodinh; k++) {
        for (int i = 0; i < g.sodinh; i++) {
            if (L[i][k] > 0) {
                for (int j = 0; j < g.sodinh; j++) {
                    if (L[k][j] > 0) {
                        if ((i != j && L[i][j] == 0) || (L[i][j] > L[i][k] + L[k][j])) {
                            L[i][j] = L[i][k] + L[k][j];
                            P[i][j] = P[k][j];
                        }
                    }
                }
            }
        }
    }
}
void printFloy(Graph g, int x, int y, string fn) {
    ofstream f(fn);
    if (f.is_open()) {
        int i = y;
        while (i != x) {
            f << i << "<--";
            i = P[x][i];
        }
        f << x << endl << "Trong so: " << L[x][y] << endl;
        f.close();
    }
}


int main() {
    Graph g;
    readgraph(g, "dothi.txt");
    Floy(g);
    printFloy(g, 1, 2, "output.txt");
    return 0;
}