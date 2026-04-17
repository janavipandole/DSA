#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void dfs(int start, int n, vector<vector<int>> &grid, vector<int> path, vector<vector<int>> &ans)
    {
        path.push_back(start);
        if (n - 1 == start)
        {
            ans.push_back(path);
            return;
        }
        else
        {
            for (auto it : grid[start])
            {
                dfs(it, n, grid, path, ans);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, n, grid, path, ans);

        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    cout << "All Paths From Source to Target : " << endl;
    vector<vector<int>> ans = s.allPathsSourceTarget(grid);
    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}