#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    void bfs(int n, int edge, vector<int> &ans, vector<vector<int>> &edges)
    {
        vector<int> visited(n + 1, 0);

        queue<pair<int, int>> q;
        q.push({edge, 0});
        visited[edge] = 1;
        int dist = 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int d = q.front().second;
            dist += d;
            q.pop();

            for (auto num : edges[node])
            {
                if (!visited[num])
                {
                    visited[num] = 1;
                    q.push({num, d + 1});
                }
            }
        }
        ans[edge] = dist;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            bfs(n, i, ans, adj);
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    int n = 6;
    cout << "Sum of Distances in Tree : " << endl;

    vector<int> ans = s.sumOfDistancesInTree(n, mat);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}