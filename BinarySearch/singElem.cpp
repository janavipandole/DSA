#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> nums = {1, 1, 4, 4, 3};
    vector<int> nums = {1, 1, 2, 2, 4, 4, 5, 5, 6, 6, 7};
    int st = 0, end = nums.size() - 1, ans = 0, ansIndex = 0;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if ((nums[mid - 1] != nums[mid] || mid == 0) && (nums[mid + 1] != nums[mid] || mid == nums.size()))
        {
            ans = nums[mid];
            ansIndex = mid;
            break;
        }
        if (mid % 2 == 0)
        {
            if (nums[mid + 1] == nums[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {
            if (nums[mid + 1] != nums[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    cout << ans << " : " << ansIndex << endl;

    return 0;
}