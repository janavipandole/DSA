#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // input for graph
    int n, m;
    cin >> n >> m;
    vector<int> mat[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u ----> v
        mat[u].push_back(v);
    }

    return 0;
}