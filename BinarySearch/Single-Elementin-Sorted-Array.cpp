#include <iostream>
#include <math.h>
using namespace std;

int single(vector<int> &nums)
{
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];

    int low = 1, high = nums.size() - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // base case
        if ((nums[mid] != nums[mid - 1]) && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (mid % 2 == 0)
        {
            if (nums[mid] != nums[mid + 1])
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
            if (nums[mid] != nums[mid + 1])
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
    vector<int> nums = {1};
    cout << "single element : " << single(nums) << endl;
    return 0;
}