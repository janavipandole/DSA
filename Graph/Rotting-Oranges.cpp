#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int changeRow[] = {-1, 0, 1, 0};
        int changeCol[] = {0, 1, 0, -1};
        int freshCount = 0;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else if (grid[i][j] == 1) freshCount++;
            }
        }

        int time = 0;
        int markFreshRotten = 0;
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);
            for (int index = 0; index < 4; index++)
            {
                int updateRow = row + changeRow[index];
                int updateCol = col + changeCol[index];

                if (updateRow >= 0 && updateRow < n && updateCol >= 0 && updateCol < m && visited[updateRow][updateCol] != 2 && grid[updateRow][updateCol] == 1)
                {
                    q.push({{updateRow, updateCol}, t + 1});
                    visited[updateRow][updateCol] = 2;
                    markFreshRotten++;
                }
            }
        }

        if (markFreshRotten != freshCount) return -1;
        
        return time;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Rotting Oranges : " << s.orangesRotting(grid) << endl;

    return 0;
}