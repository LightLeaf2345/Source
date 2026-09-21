#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int Max = 100;
int visited[Max];
int nT = 0;

struct EDGE 
{
    int u, v, w;
};

struct GRAPH 
{
    int sodinh; 
    int a[Max][Max];
    EDGE T[Max]; 
    int sumT;
};

void sortEDGE(int soCanh, EDGE E[]) 
{
    for (int i = 0; i < soCanh; i++) 
    {
        int a = i;
        for (int j = i + 1; j < soCanh; j++) 
        {
            if (E[a].w < E[j].w) 
            {
                a = j;
            }
        }
        swap(E[a], E[i]);
    }
}

void KhoiTaoMangCanh(GRAPH g, int& nCanh, EDGE DSCanh[]) 
{
    for (int i = 0; i < g.sodinh; i++) 
    {
        for (int j = i; j < g.sodinh; j++) 
        {
            if (g.a[i][j] != 0) 
            {
                DSCanh[nCanh++] = { i, j, g.a[i][j] };
            }
        }
    }
}

void readGraph(string fn, GRAPH& g) 
{
    fstream f;
    f.open(fn);

    if (f.is_open()) 
    {
        f >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++) 
        {
            for (int j = 0; j < g.sodinh; j++) 
            {
                f >> g.a[i][j];
            }
        }
        f.close();
    }
}

void printGraph(string fn, GRAPH g) 
{
    ofstream f;
    f.open(fn, ios::out);

    if (f.is_open()) {
        f << "So dinh: " << g.sodinh << endl;
        for (int i = 0; i < g.sodinh; i++) {
            for (int j = 0; j < g.sodinh; j++) 
            {
                f << setw(4) << g.a[i][j];
            }
            f << endl;
        }
        f.close();
    }
    else {
        cout << "Khong the mo file " << fn;
    }
}

void DFS(int u, GRAPH& g, bool visited[]) 
{
    visited[u] = true;
    for (int v = 0; v < g.sodinh; v++) 
    {
        if (g.a[u][v] != 0 && !visited[v]) 
        {
            DFS(v, g, visited);
        }
    }
}

bool isConnected(GRAPH g) 
{
    bool visited[Max] = { false };
    DFS(0, g, visited);

    for (int i = 0; i < g.sodinh; i++) 
    {
        if (!visited[i]) 
        {
            return false; 
        }
    }
    return true;
}

bool CoChuTrinh(GRAPH g, int iMin, EDGE DSCanh[], int Nhan[]) 
{
    if (Nhan[DSCanh[iMin].u] != Nhan[DSCanh[iMin].v]) 
    {
        for (int i = 0; i < g.sodinh; i++) 
        {
            if (Nhan[i] == Nhan[DSCanh[iMin].v] && i != DSCanh[iMin].v) 
            {
                Nhan[i] = Nhan[DSCanh[iMin].u];
            }
        }
        Nhan[DSCanh[iMin].v] = Nhan[DSCanh[iMin].u];
        return false;
    }
    return true;
}

bool unionComponents(int u, int v, int Nhan[]) 
{
    if (Nhan[u] != Nhan[v]) 
    {
        int oldVal = Nhan[v];
        for (int i = 0; i < Max; i++) 
        {
            if (Nhan[i] == oldVal) 
            {
                Nhan[i] = Nhan[u];
            }
        }
        return false;
    }
    return true;
}

void kruskal(GRAPH& g) 
{
    EDGE DSCanh[100];
    int nCanh = 0;

    KhoiTaoMangCanh(g, nCanh, DSCanh);

    sortEDGE(nCanh, DSCanh);

    int Nhan[Max];
    for (int i = 0; i < g.sodinh; i++) Nhan[i] = i;

    nT = 0;
    g.sumT = 0;

    for (int i = 0; i < nCanh; i++) 
    {
        if (!unionComponents(DSCanh[i].u, DSCanh[i].v, Nhan)) 
        {
            g.T[nT++] = DSCanh[i];
            g.sumT += DSCanh[i].w;
        }
    }

}

void printSpanningTree(string fn, GRAPH g) 
{
    ofstream f;
    f.open(fn);

    kruskal(g);

    if (f.is_open()) 
    {
        f << "Cay khung nho nhat cua do thi la: " << endl;
        for (int i = 0; i < nT; i++) 
        {
            f << "(" << g.T[i].u << ", " << g.T[i].v << ") ";
        }
        f << endl;
        f << "Tong gia tri cua cay la: " << g.sumT << endl;
        f.close();
    }
    else 
    {
        cout << "Khong the mo file " << fn;
    }
}

int main() 
{
    GRAPH g;
    readGraph("dothi.txt", g);
    if (isConnected(g)) 
    {
        printSpanningTree("output.txt", g);
    }
    return 0;
}