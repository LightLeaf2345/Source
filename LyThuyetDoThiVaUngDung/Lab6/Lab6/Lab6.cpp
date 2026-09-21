#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>

using namespace std;

const int Max = 100;
int LastV[Max]; 
bool ThuocT[Max]; 
int Length[Max]; 

struct GRAPH {
    int sodinh; 
    int adj[Max][Max]; 
};

void readGraph(const string& fn, GRAPH& g)
{
    ifstream f(fn);
    if (f.is_open())
    {
        f >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++)
        {
            for (int j = 0; j < g.sodinh; j++)
            {
                f >> g.adj[i][j];
            }
        }
        f.close();
    }
}

int minLength(int length[], bool visited[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && length[v] <= min) {
            min = length[v];
            min_index = v;
        }
    }
    return min_index;
}

void Dijkstra(GRAPH g, int x, int y)
{
    int min = -1;
    int i;
    for (int i = 0; i < g.sodinh; i++)
    {
        ThuocT[i] = true;
        Length[i] = VoCuc;
        LastV[i] = -1;
    }
    Length[i] = 0;
    ThuocT[i] = false; 
    LastV[i] = -1;

    int v = x;
    while (ThuocT[y])
    {
        for (int k = 0; k < g.sodinh; k++)
        {
            if (g.adj[v][k] != 0 && ThuocT[k] == true && (Length[k] == VoCuc || Length[k] > Length[v] + g.adj[v][k]))
            {
                Length[k] = Length[v] + g.adj[v][k];
                LastV[k] = v;
            }
        }
        v = -1;
        for (int k = 0; k < g.sodinh; k++)
        {
            if (ThuocT[i] == true && Length[i] != VoCuc)
            {
                if (v == -1 || (Length[v] > Length[i]))
                {
                    v=i;
                }
            }
        }
        if (v == 1)
        {
            break;
        }
        ThuocT[v] = false;
    }
//void Dijkstra(GRAPH g, int i, int j) 
//{
//    for (int i = 0; i < g.sodinh; i++) 
//    {
//        Length[i] = INT_MAX; 
//        ThuocT[i] = false; 
//        LastV[i] = -1;
//    }
//
//    Length[i] = 0; 
//
//    for (int count = 0; count < g.sodinh - 1; count++) 
//    {
//
//        int v = -1;
//        for (int k = 0; k < g.sodinh; k++) 
//        {
//            if (!ThuocT[k] && (v == -1 || Length[k] < Length[v])) 
//            {
//                v = k;
//            }
//        }
//
//        ThuocT[v] = true;
//
//        for (int k = 0; k < g.sodinh; k++) 
//        {
//            if (!ThuocT[k] && g.adj[v][k] != 0 && Length[v] != INT_MAX &&
//                Length[v] + g.adj[v][k] < Length[k]) 
//            {
//                Length[k] = Length[v] + g.adj[v][k];
//                LastV[k] = v; 
//            }
//        }
//    }

/*void Xuat(int x, int y) {
    int DuongDi[Max];
    int i = y;
    int id = 0;

    while (i != x) {
        DuongDi[id] = i;
        i = LastV[i];
        id++;
    }
    DuongDi[id] = x;

    cout << "Duong Di tu " << x << " den " << y << ": ";
    for (int j = id; j >= 0; j--) {
        cout << DuongDi[j] << (j == 0 ? "" : " -> ");
    }
    cout << endl;
}*/
void

    if (Length[j] != INT_MAX) {
        cout << "Shortest distance from " << i << " to " << j << " is " << Length[j] << endl;
        Xuat(i, j); 
    }
    else {
        cout << "No path exists from " << i << " to " << j << endl;
    }
}
void Floy(GRAPH g)// chay k trc roi i va j, chay khac thu tu thi no sai do
{
    for (int k = 0; k < g.sodinh; k++)
    {
        for (int i = 0; i < g.sodinh; i++)
        {
            if (L[i][k] > 0)
            {
                for(i)
                {
                    if (L[k][j] > 0)
                    {
                        if ((i != j && L[i][j] == 0) || L[i][j] < L[i][k])
                        {
                            L[i][j] = L[i][k] + L[k][j];
                            P[i][j] = P[k][j]
                        }
                    }
                }
                    
            }
        }
    }
}
void XuatFloy(int x, int y)
{
    int v = y;
    DD[0] = y;
    id = 1;
    while (v != x)
    {
        DD[id++] = P[x][v];
        v = P[x][v];
    }
}

int main() 
{
    GRAPH g;
    readGraph("input.txt", g); 
    Dijkstra(g, 0, 3);
    return 0;
}
