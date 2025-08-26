#include <iostream>
#include <math.h>
using namespace std;

bool isPossible(vector<int> &nums, int k, int possible)
{
    int board = 1;
    int lengthBoard = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > possible)
        {
            return false;
        }
        if (nums[i] + lengthBoard <= possible)
        {
            lengthBoard += nums[i];
        }
        else
        {
            lengthBoard = nums[i];
            board++;
        }
    }
    return board <= k;
}

// Brute force solution
int splitArrayBrute(vector<int> &nums, int k)
{
    if (nums.size() < k)
    {
        return -1;
    }

    int low = *min_element(nums.begin(), nums.end());
    int high = 0;

    for (auto num : nums)
    {
        high += num;
    }

    for (int i = low; i <= high; i++)
    {
        if (isPossible(nums, k, i))
        {
            return i;
        }
    }
    return -1;
}

// optimal solution
int splitArrayOptimal(vector<int> &nums, int k)
{
    if (nums.size() < k)
    {
        return -1;
    }

    int low = *min_element(nums.begin(), nums.end());
    int high = 0;

    for (auto num : nums)
    {
        high += num;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isPossible(nums, k, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> nums = {7,2,5,10,8};
    int k = 2;

    cout << "min Time : " << splitArrayBrute(nums, k) << endl;
    cout << "min Time : " << splitArrayOptimal(nums, k) << endl;
    return 0;
}