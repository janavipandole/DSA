#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    void DFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &vec, int rowBase, int colBase)
    {
        visited[i][j] = 1;
        vec.push_back({i - rowBase, j - colBase});

        int n = grid.size();
        int m = grid[0].size();

        int changeRow[] = {-1, 1, 0, 0};
        int changeCol[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int row = i + changeRow[k];
            int col = j + changeCol[k];

            if (row >= 0 && row < n && col >= 0 && col < m &&
                visited[row][col] == 0 && grid[row][col] == 1)
            {
                DFS(row, col, grid, visited, vec, rowBase, colBase);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    vector<pair<int, int>> vec;
                    DFS(i, j, grid, visited, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
    cout << "Number of Distinct Islands: " << s.countDistinctIslands(grid) << endl;

    return 0;
}