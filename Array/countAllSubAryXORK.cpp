#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
int countSubarraysWithXORBrute(const vector<int> &arr, int x)
{
    int count = 0;
    int n = arr.size();

    //{4, 2, 2, 6, 4}
    for (int i = 0; i < n; ++i)
    {

        for (int j = i; j < n; ++j)
        {
            int xorSum = 0;
            for (int k = i; k <= j; k++)
            {
                xorSum ^= arr[k];
            }
            if (xorSum == x)
            {
                count++;
            }
        }
    }
    return count;
}

int countSubarraysWithXORBetter(const vector<int> &arr, int x)
{
    int count = 0;
    int n = arr.size();

    //{4, 2, 2, 6, 4}
    for (int i = 0; i < n; ++i)
    {
        int xorSum = 0;
        for (int j = i; j < n; ++j)
        {
            xorSum ^= arr[j];
            if (xorSum == x)
            {
                count++;
            }
        }
    }
    return count;
}

int countSubarraysWithXOROptimal(vector<int> nums, int x)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1; // To handle the case when the subarray starts from index 0
    int cnt = 0;
    int xorSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xorSum ^= nums[i];
        int requiredXor = xorSum ^ x;
        if (mpp.find(requiredXor) != mpp.end())
        {
            cnt += mpp[requiredXor];
        }
        mpp[xorSum]++;
    }
    return cnt;
}
};
int main()
{
    Solution s;
    vector<int> nums = {4, 2, 2, 6, 4};
    int x = 6;
    cout << "count Sub arrays With XOR : " << s.countSubarraysWithXORBrute(nums, x) << endl;
    cout << "count Sub arrays With XOR : " << s.countSubarraysWithXORBetter(nums, x) << endl;
    cout << "count Sub arrays With XOR : " << s.countSubarraysWithXOROptimal(nums, x) << endl;
    return 0;
}