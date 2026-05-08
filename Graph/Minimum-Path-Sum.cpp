#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
 void DFS(int i, int j, int countAnswer, vector<vector<int>> &grid, int &minAnswer)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m) return;
    
        if (i == n - 1 && j == m - 1)
        {
            minAnswer = min(minAnswer, countAnswer+ grid[i][j]);
            return;
        }
       
        DFS(i+1, j, countAnswer + grid[i][j], grid, minAnswer);
        DFS(i, j+1, countAnswer + grid[i][j], grid, minAnswer);
    }
    int minPathSum(vector<vector<int>> &grid)
    {

        int minAnswer = INT_MAX;
        DFS(0, 0, 0, grid, minAnswer);
        return minAnswer;
    }
};

int main()
{
    Solution s;
    int n = 3, m = 3;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Minimum Path Sum : " << s.minPathSum(grid) << endl;

    return 0;
}