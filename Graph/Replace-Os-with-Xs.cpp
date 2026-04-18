#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void DFS(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1 || grid[i][j] == 'X')
            return;

        int changeRow[] = {-1, 1, 0, 0};
        int changeCol[] = {0, 0, -1, 1};

        visited[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            DFS(i + changeRow[k], j + changeCol[k], grid, visited);
        }
    }

    void fill(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 'O' && visited[0][j] == 0)
            {
                DFS(0, j, grid, visited);
            }

            if (grid[n - 1][j] == 'O' && visited[n - 1][j] == 0)
            {
                DFS(n - 1, j, grid, visited);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 'O' && visited[i][0] == 0)
            {
                DFS(i, 0, grid, visited);
            }
            if (grid[i][m - 1] == 'O' && visited[i][m - 1] == 0)
            {
                DFS(i, m - 1, grid, visited);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == 'O')
                {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<char>> grid = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'O', 'X', 'X'}, {'X', 'X', 'O', 'O'}};
    cout << "Replace O's with X's : " << endl;
    s.fill(grid);
    for (auto chars : grid)
    {
        for (auto ch : chars)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}