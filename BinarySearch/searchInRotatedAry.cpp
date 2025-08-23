#include <iostream>
using namespace std;

int search(vector<int> &nums, int key)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == key)
        {
            return mid;
        }

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
        else
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
    return -1;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "search : " << search(nums, target) << endl;
    return 0;
}