#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> answer(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        int changeRow[] = {-1, 1, 0, 0};
        int changeCol[] = {0, 0, -1, 1};
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            answer[row][col] = step;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + changeRow[i];
                int newCol = col + changeCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol] == 0 && grid[newRow][newCol] != 1)
                {
                    q.push({{newRow, newCol}, step + 1});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        return answer;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    cout << "Distance of nearest cell having 1 : " << endl;

    vector<vector<int>> answer = s.nearest(grid);
    for (auto nums : answer)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}