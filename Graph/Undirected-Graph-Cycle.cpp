#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool bfs(int src, vector<int> adjList[], vector<int> &visit)
    {
        visit[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto num : adjList[node])
            {
                if (!visit[num])
                {
                    visit[num] = 1;
                    q.push({num, node});
                }
                else if (parent != num)
                {
                    return true;
                }
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
                if (bfs(i, adjList, visit))
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
    cout << "Undirected Graph Cycle : " << s.isCycle(n, edges) << endl;
    return 0;
}