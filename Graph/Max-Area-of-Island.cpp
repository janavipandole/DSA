#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) return 0;

        grid[i][j] = 0;

        return 1 + dfs(grid, i - 1, j, n, m) + dfs(grid, i + 1, j, n, m) +
               dfs(grid, i, j - 1, n, m) + dfs(grid, i, j + 1, n, m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j, n, m));
                }
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 0, 1, 1}, {0, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 0, 0}};
    cout << "Max Area of Island : " << s.maxAreaOfIsland(grid) << endl;

    return 0;
}