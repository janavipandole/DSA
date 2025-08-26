#include <iostream>
using namespace std;

int getTarget(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 4, 5, 6, 7, 8, 9, 10};
    int target = 9;

    cout << getTarget(nums, target) << endl;
    return 0;
}