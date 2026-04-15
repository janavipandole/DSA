#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void DFS(vector<vector<int>> &adj, vector<int> &ans, vector<int> &visited, int index)
    {
        visited[index] = 1;
        ans.push_back(index);

        for (auto it : adj[index])
        {
            if (!visited[it])
            {
                DFS(adj, ans, visited, it);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<int> ans;
        int n = adj.size();
        vector<int> visited(n + 1, 0);
        int index = 0;
        DFS(adj, ans, visited, index);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    cout << "DFS of grap : " << endl;

    vector<int> ans = s.dfs(mat);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}