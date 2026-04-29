#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    void DFS(int node, vector<int> adjList[], vector<int> &visited)
    {
        visited[node] = 1;

        for (auto adj : adjList[node])
        {
            if (!visited[adj])
            {
                DFS(adj, adjList, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> adjList[n];
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto room : rooms[i])
            {
                adjList[i].push_back(room);
            }
        }

        DFS(0, adjList, visited);
        return all_of(visited.begin(), visited.end(), [](int visited) { return visited == 1; });
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{1}, {2}, {3}, {}};
    cout << "Keys and Rooms : " << s.canVisitAllRooms(edges) << endl;

    return 0;
}