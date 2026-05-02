#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    void topoSort(vector<int> &visited, vector<pair<int, int>> adjList[], stack<int> &st, int node)
    {
        visited[node] = 1;

        for (auto it : adjList[node])
        {
            int v = it.first;
            if (!visited[v])
            {
                topoSort(visited, adjList, st, v);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<int> visited(V, 0);
        vector<pair<int, int>> adjList[V];
        stack<int> st;

        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topoSort(visited, adjList, st, i);
            }
        }
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        while (!st.empty())
        {
            auto node = st.top();
            st.pop();

            for (auto it : adjList[node])
            {
                auto v = it.first;
                auto wt = it.second;

                if (distance[node] != INT_MAX && distance[node] + wt < distance[v])
                {
                    distance[v] = distance[node] + wt;
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }
        return distance;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}};
    int V = 4, E = 2;
    cout << "Shortest path in Directed Acyclic Graph : " << endl;
    vector<int> answer = s.shortestPath(V, E, edges);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}