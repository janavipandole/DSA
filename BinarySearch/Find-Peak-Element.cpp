#include <iostream>
using namespace std;

// Brute force
vector<int> findPeakGridBrute(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || mat[i][j] > mat[i - 1][j]) &&
                (i == n - 1 || mat[i][j] > mat[i + 1][j]) &&
                (j == 0 || mat[i][j] > mat[i][j - 1]) &&
                (j == m - 1 || mat[i][j] > mat[i][j + 1]))
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Optimal solution
int maxIndex(vector<vector<int>> &mat, int col, int n)
{
    int index = -1;
    int maxElem = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxElem)
        {
            maxElem = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGridOptimal(vector<vector<int>> &mat)
{
    int m = mat[0].size() - 1, n = mat.size();
    int low = 0, high = m;
    while (low <= high)
    {
        int col = (low + high) / 2;
        int row = maxIndex(mat, col, n);
        int left = col - 1 >= 0 ? mat[row][col - 1] : -1;
        int right = col + 1 < m ? mat[row][col + 1] : -1;

        if (mat[row][col] > left && mat[row][col] > right)
        {
            return {row, col};
        }
        else if (mat[row][col] < left)
        {
            high = col - 1;
        }
        else
        {
            low = col + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {{14, 10}, {16, 20}};
    vector<int> nums = findPeakGridOptimal(mat);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}