#include <iostream>
#include <vector>
using namespace std;

int main()
{
                     // 0, 1, 2, 3, 4, 5, 6, 7, 8
    vector<int> nums = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int st = 0;
    int end = nums.size() - 1;
    int tar = 9;
    int ans = 0;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == tar)
        {
            ans = mid;
            break;
        }

        if (nums[st] <= tar && tar <= nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    cout << "Answer  " << tar << " is present at : " << ans << endl;
    return 0;
}