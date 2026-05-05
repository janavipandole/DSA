#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<pair<int, int>> adjList[V];
        vector<int> distance(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        distance[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto dist = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            for (auto it : adjList[node])
            {
                int adjNode = it.first;
                int edegWeight = it.second;

                if (dist + edegWeight < distance[adjNode])
                {
                    distance[adjNode] = dist + edegWeight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
    int V = 3, src = 2;
    cout << "Dijkstra's Algorithm - Using Priority Queue : " << endl;
    vector<int> answer = s.dijkstra(V, edges, src);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}