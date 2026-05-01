#include <iostream>
using namespace std;
class Solution1
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

        for (int i = 0; i < V; i++)
        {
            for (auto v : edges[i])
            {
                adjList[i].push_back(v);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (!visit[i])
                dfs(i, adjList, visit, checks, pathVisit);
        }

        for (int i = 0; i < V; i++)
        {
            if (checks[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
class Solution2
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &edges)
    {
        int V = edges.size();
        queue<int> q;
        vector<int> visit(V, 0);
        vector<int> inDegree(V, 0);
        vector<int> adjList[V];
        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            for (auto v : edges[i])
            {
                adjList[v].push_back(i);
                inDegree[i]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)q.push(i);
        }

        while (!q.empty())
        {
            auto node = q.front();
            safeNodes.push_back(node);
            q.pop();

            for (auto adj : adjList[node])
            {
                inDegree[adj]--;
                if (inDegree[adj] == 0)q.push(adj);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
int main()
{
    Solution1 s;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    cout << "Find Eventual Safe States : " << endl;
    vector<int> answer = s.eventualSafeNodes(edges);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}