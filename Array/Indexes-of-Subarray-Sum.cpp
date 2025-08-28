#include <iostream>
using namespace std;
vector<int> subarraySum(vector<int> &nums, int target)
{
    int i = 0;
    int sum = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];
        if (sum > target && i < j)
        {
            sum -= nums[i];
            i++;
        }
        if (target == sum)
        {
            return {i + 1, j + 1};
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