#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<int> adjList[], vector<int> &visit, vector<int> &pathVisit)
    {
        visit[node] = 1;
        pathVisit[node] = 1;
        for (auto adjNode : adjList[node])
        {
            if (visit[adjNode] == 0)
            {
                if (dfs(adjNode, adjList, visit, pathVisit))return true;
            }
            else if (pathVisit[adjNode] == 1) return true;
        }
        pathVisit[node] = 0;
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> visit(V, 0);
        vector<int> pathVisit(V, 0);
        vector<int> adjList[V];

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visit[i])
            {
                if (dfs(i, adjList, visit, pathVisit))
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
    vector<vector<int>> edges = {{3},{3, 0}, {4, 2}, {1, 2}};
    int n = 5;
    cout << "Directed Graph Cycle using DFS : " << s.isCycle(n, edges) << endl;
    return 0;
}