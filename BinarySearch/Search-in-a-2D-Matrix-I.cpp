#include <iostream>
using namespace std;
// Brute force solution
bool searchMatrixBrute(vector<vector<int>> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            if (nums[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
// Better solution
bool BS(vector<int> &arr, int target, int m)
{
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return true;
        }

        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
bool searchMatrixBetter(vector<vector<int>> &nums, int target)
{
    int m = nums[0].size();
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i][0] <= target && nums[i][m - 1])
        {
            return BS(nums[i], target, m);
        }
    }
    return false;
}
// Optimal solution - I
bool searchMatrixOptimalI(vector<vector<int>> &nums, int target)
{
    int n = nums.size();
    int m = nums[0].size();

    int low = 0;
    int high = (n * m) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int row = mid / m;
        int col = mid % m;

        if (nums[row][col] == target)
            return true;
        else if (nums[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
// Optimal solution - II
bool searchInRow(vector<vector<int>> &mat, int tar, int row, int n)
{
    int st = 0, end = n - 1; // 3

    while (st <= end)
    {
        int mid = st + (end - st) / 2; // 1

        if (tar == mat[row][mid])
        {
            return true;
        }
        else if (tar > mat[row][mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

bool searchMatrixOptimalII(vector<vector<int>> &mat, int tar)
{
    // BS on to the rows
    int m = mat.size();    // 3
    int n = mat[0].size(); // 4

    int startRow = 0;
    int endRow = m - 1; // 2

    while (startRow <= endRow)
    {
        int midRow = startRow + (endRow - startRow) / 2; // 1 0

        if (tar >= mat[midRow][0] && tar <= mat[midRow][n - 1])
        {
            return searchInRow(mat, tar, midRow, n);
        }
        else if (tar >= mat[midRow][n - 1])
        {
            startRow = midRow + 1;
        }
        else
        {
            endRow = midRow - 1; // 0
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << "searchMatrix : " << searchMatrixBrute(nums, target) << endl;
    cout << "searchMatrix : " << searchMatrixBetter(nums, target) << endl;
    cout << "searchMatrix : " << searchMatrixOptimalI(nums, target) << endl;
    cout << "searchMatrix : " << searchMatrixOptimalII(nums, target) << endl;

    return 0;
}