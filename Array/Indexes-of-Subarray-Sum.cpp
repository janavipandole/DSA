#include <iostream>
using namespace std;
vector<int> subarraySum(vector<int> &nums, int target)
{
    int start = 0, sum = 0;

    for (int end = 0; end < nums.size(); ++end)
    {
        sum += nums[end];

        // Shrink window from the left if sum exceeds target
        while (sum > target && start < end)
        {
            sum -= nums[start++];
        }

        if (sum == target)
        {
            return {start + 1, end + 1}; // 1-based indexing
        }
    }

    return {-1};
}
int main()
{
    vector<int> nums = {7, 31, 14, 19, 1, 42, 13, 6, 11, 10, 25, 38, 49, 34, 46, 42, 3, 1};
    int target = 42;
    vector<int> ans = subarraySum(nums, target);
    cout << "subarray Sum" << endl;
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}