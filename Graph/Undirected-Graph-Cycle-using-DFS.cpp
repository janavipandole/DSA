#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool dfs(int node, int parent, vector<int> adjList[], vector<int> &visit)
    {
        visit[node] = 1;
        for (auto adjNode : adjList[node])
        {
            if (!visit[adjNode])
            {
                if (dfs(adjNode, node, adjList, visit)) return true;
                else if(adjNode != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int n, vector<vector<int>> &edges)
    {
        vector<int> visit(n, 0);
        vector<int> adjList[n];

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                if (dfs(i, -1, adjList, visit))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    int n = 4;
    cout << "Undirected Graph Cycle using DFS : " << s.isCycle(n, edges) << endl;
    return 0;
}