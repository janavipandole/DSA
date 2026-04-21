#include <iostream>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<int> adjList[], vector<int> &visit, vector<int> &checks, vector<int> &pathVisit)
    {
        visit[node] = 1;
        pathVisit[node] = 1;
        checks[node] = 0;
        for (auto adjNode : adjList[node])
        {
            if (!visit[adjNode])
            {
                if (dfs(adjNode, adjList, visit, checks, pathVisit))
                {
                    return true;
                }
            }
            else if (pathVisit[adjNode])
            {
                return true;
            }
        }
        checks[node] = 1;
        pathVisit[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &edges)
    {
        int V = edges.size();
        vector<int> visit(V, 0);
        vector<int> pathVisit(V, 0);
        vector<int> adjList[V];
        vector<int> checks(V, 0);
        vector<int> safeNodes;

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visit[i])
                dfs(i, adjList, visit, checks, pathVisit);
        }

        for (int i = 0; i < V; i++)
        {
            if (checks[i] == 1)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
    cout << "Find Eventual Safe States : " << endl;
    vector<int> answer = s.eventualSafeNodes(edges);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}