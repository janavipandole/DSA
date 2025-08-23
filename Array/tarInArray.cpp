#include <iostream>
#include <vector>
using namespace std;

bool targetAtCol(vector<vector<int>> &nums, int tar, int row)
{
    int st = 0, end = nums[0].size()-1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums[row][mid] == tar)
        {
            return true;
        }
        if (tar > nums[row][mid])
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
bool targetAtIndex(vector<vector<int>> &nums, int tar)
{
    int st = 0;
    int end = nums.size() - 1;
    int n = nums[0].size() - 1;
    while (st <= end)
    {
        int midRow = st + (end - st) / 2;

        if (tar >= nums[midRow][0] && tar <= nums[midRow][n])
        {
            return targetAtCol(nums, tar, midRow);
        }
        if (tar >= nums[midRow][n])
        {
            st = midRow + 1;
        }
        else
        {
            end = midRow - 1;
        }
    }
    return false;
}

int main()
{
    // here each row is sorted in non decening order
    // last elem of each row is smaller than the first elem of the next row
    // if we arrange mat in linear fashion we can say tha array is complete sorted

    vector<vector<int>> nums = {{1, 3, 5, 7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 60}};
    int tar = 34;

    cout<<"is tar paresent ?? : "<<targetAtIndex(nums, tar)<<endl;
    return 0;
}