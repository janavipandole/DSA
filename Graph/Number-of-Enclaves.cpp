#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void DFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 0 || grid[i][j] == 0) return;

        int changeRow[] = {-1, 1, 0, 0};
        int changeCol[] = {0, 0, -1, 1};

        visited[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            DFS(i + changeRow[k], j + changeCol[k], grid, visited);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 1));

        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1 && visited[0][j] == 1) DFS(0, j, grid, visited);
            if (grid[n - 1][j] == 1 && visited[n - 1][j] == 1) DFS(n - 1, j, grid, visited);
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1 && visited[i][0] == 1) DFS(i, 0, grid, visited);
            if (grid[i][m - 1] == 1 && visited[i][m - 1] == 1) DFS(i, m - 1, grid, visited);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 1 && grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << "Number of Enclaves : " << s.numEnclaves(grid) << endl;

    return 0;
}