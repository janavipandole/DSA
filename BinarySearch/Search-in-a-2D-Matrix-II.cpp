#include <iostream>
using namespace std;
// Brute force solution
pair<int, int> searchMatrixBrute(vector<vector<int>> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            if (nums[i][j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
// Better solution
int BS(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
pair<int, int> searchMatrixBetter(vector<vector<int>> &nums, int target)
{
    if (nums.empty() || nums[0].empty())
    {
        return {-1, -1};
    }
    int m = nums[0].size();
    int index = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i][0] <= target && target <= nums[i][m - 1])
        {
            index = BS(nums[i], target);
            if (index != -1)
            {
                return {i, index};
            }
        }
    }
    return {-1, -1};
}
// Optimal solution
pair<int, int> searchMatrixOptimal(vector<vector<int>> &nums, int target)
{
    int row = 0, col = nums[0].size() - 1;
    int n = nums.size();
    while (row < n && col >= 0)
    {
        if (nums[row][col] == target)
        {
            return {row, col};
        }

        if (nums[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> nums = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 14;
    pair<int, int> ans1 = searchMatrixBrute(nums, target);
    cout << "search Matrix Brute: " << "{" << ans1.first << " " << ans1.second << "}" << endl;

    pair<int, int> ans2 = searchMatrixBetter(nums, target);
    cout << "search Matrix Brute: " << "{" << ans2.first << " " << ans2.second << "}" << endl;

    pair<int, int> ans3 = searchMatrixOptimal(nums, target);
    cout << "search Matrix Brute: " << "{" << ans3.first << " " << ans3.second << "}" << endl;

    return 0;
}