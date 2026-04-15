#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> ans;
        int n = adj.size();
        vector<int> visited(n + 1, 0);

        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto num : adj[node])
            {
                if (!visited[num])
                {
                    visited[num] = 1;
                    q.push(num);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    cout << "BFS of grap : " << endl;

    vector<int> ans = s.bfs(mat);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}