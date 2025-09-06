#include <iostream>
#include <math.h>
using namespace std;
// brute force solution
int singleNumberIIBrute(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (auto num : nums)
        m[num]++;

    for (auto &[val, count] : m)
    {
        if (count == 1)
            return val;
    }
    return -1;
}
// Optimal solution
int singleNumberIIBetter(vector<int> &nums)
{
    int ans = 0;
    for (int bitIndex = 0; bitIndex < 32; bitIndex++)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & (1 << bitIndex))
                cnt++;
        }
        if (cnt % 3 == 1)
        {
            ans |= (1 << bitIndex);
        }
    }
    return ans;
}
int singleNumberIIOptimal(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n - 1; i += 3)
    {
        if (nums[i - 1] != nums[i])
        {
            return nums[i - 1];
        }
    }
    return nums[n - 1];
}

int singleNumberIIMostOptimal(vector<int> &nums)
{
    int ones = 0, twos = 0;
    for (auto num : nums)
    {
        ones = ones ^ num & (~twos);
        twos = twos ^ num & (~ones);
    }
    return ones;
}

int main()
{
    vector<int> nums = {0, 0, 0, 1, 1, 1, 99};
    cout << "Single Number : " << singleNumberIIBrute(nums) << endl;
    cout << "Single Number : " << singleNumberIIBetter(nums) << endl;
    cout << "Single Number : " << singleNumberIIOptimal(nums) << endl;
    cout << "Single Number : " << singleNumberIIMostOptimal(nums) << endl;

    return 0;
}