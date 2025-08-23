#include <iostream>
using namespace std;
bool search(vector<int> &nums, int key)
{
    int low = 0, high = nums.size() - 1;

    // standerd BS
    while (low <= high)
    {
        // find mid here
        int mid = low + (high - low) / 2;

        // base case
        if (nums[mid] == key)
        {
            return true;
        }

        // Imp testing for rotated sorted array 2 problem remaing thins after this test case are same
        if (nums[low] == nums[mid] && nums[high] == nums[mid])
        {
            low++;
            high--;
            continue;
        }

        // same code of rotated sorted array 1
        // if left is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= key && key <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else // Right part is sorted
        {
            if (nums[mid] <= key && key <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {4, 5, 8, 1, 1, 1, 2};
    int key = 6;
    cout << "search : " << search(nums, key) << endl;
    return 0;
}