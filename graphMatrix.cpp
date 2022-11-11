#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World";
    int m, n; // m is the number of vertices and n is the number of edges
    cin >> m >> n;
    int a[m + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    cout << "The adjacency matrix is: a[u][v] " << endl;
    return 0;
}
