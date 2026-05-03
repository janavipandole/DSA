#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> adjList[V];
        vector<int> distance(V, 1e9);
        queue<int> q;

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        distance[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (auto it : adjList[node])
            {
                if (distance[it] == 1e9)
                {
                    distance[it] = 1 + distance[node];
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (distance[i] == 1e9)
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
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 4}, {4, 5}, {2, 6}, {5, 6}, {6, 7}, {6, 8}, {7, 8}};
    int V = 9, src = 0;
    cout << "Shortest Path in Undirected Graph : " << endl;
    vector<int> answer = s.shortestPath(V, edges, src);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}