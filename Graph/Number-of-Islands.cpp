#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
public:
    void dfs(vector<vector<char>> grid, int i, int j, int n, int m)
    {
        if (i < 0 || i > n || j < 0 || j > m || grid[i][j] != '1')
            return;

        grid[i][j] = '0';
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i, j + 1, n, m);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }

        return count;
    }
};

class Solution2
{
public:
    void bfs(vector<vector<char>> grid, int i, int j, int n, int m)
    {
        grid[i][j] = '0';
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int newRow = -1; newRow <= 1; newRow++)
            {
                for (int newCol = -1; newCol <= 1; newCol++)
                {
                    int updateRow = row + newRow;
                    int updateCol = col + newCol;
                    if(updateRow >= 0 && updateRow < n && updateCol >= 0 && updateCol < m && grid[updateRow][updateCol] == '1'){
                        q.push({updateRow,updateCol});
                        grid[updateRow][updateCol] = '0';
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    bfs(grid, i, j, n, m);
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution2 s;
    vector<vector<char>> grid = {{'0', '0', '0', '0'}};
    cout << "Number of Islands : " << s.numIslands(grid) << endl;

    return 0;
}