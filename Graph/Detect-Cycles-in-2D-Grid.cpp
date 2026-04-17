#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool dfs(int i, int j, int p_i, int p_j,
             vector<vector<char>> &grid,
             vector<vector<int>> &visit){
        int n = grid.size();
        int m = grid[0].size();

        char ch = grid[i][j];
        visit[i][j] = 1;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int ni = i + drow[k];
            int nj = j + dcol[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == ch)
            {
                if (!visit[ni][nj])
                {
                    if (dfs(ni, nj, i, j, grid, visit))
                    {
                        return true;
                    }
                }
                else if (ni == p_i && nj == p_j)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visit[i][j] == 0)
                {
                    if (dfs(i, j, -1, -1, grid, visit))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> grid = {{'a', 'a', 'a', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'a', 'a', 'a'}};
    cout << "Detect Cycles in 2D Grid : " << s.containsCycle(grid) << endl;
    return 0;
}