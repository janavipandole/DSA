#include <iostream>
using namespace std;
// Find the length of SubArray with sum <= k
class Solution
{
public:
    // Brute force soluiton
    // TC = O(n^2)
    int lengthOfSubarray_Brute(vector<int> &nums, int k)
    {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j <= nums.size(); j++)
            {
                sum += nums[j];
                if (sum <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                if (sum > k)
                {
                    break;
                }
            }
        }
        return maxLen;
    }

    // Better soluiton
    // TC = O(2n)
    int lengthOfSubarray_Better(vector<int> &nums, int k)
    {
        int maxLen = 0, l = 0, r = 0, sum = 0;
        while (r < nums.size())
        {
            sum += nums[r];
            r++;

            while (sum > k)
            {
                sum -= nums[l];
                l++;
            }

            if (sum <= k)
            {
                maxLen = max(maxLen, r - l);
            }
        }
        return maxLen;
    }

     // Optimal soluiton
    // TC = O(n)
    int lengthOfSubarray_Optimal(vector<int> &nums, int k)
    {
        int maxLen = 0, l = 0, r = 0, sum = 0;
        while (r < nums.size())
        {
            sum += nums[r];
            r++;

            if (sum > k)
            {
                sum -= nums[l];
                l++;
            }

            if (sum <= k)
            {
                maxLen = max(maxLen, r - l);
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 5, 7, 1, 10};
    int k = 14;
    cout << "Find the length of SubArray with sum <= k : " << s.lengthOfSubarray_Brute(nums, k) << endl;
    cout << "Find the length of SubArray with sum <= k : " << s.lengthOfSubarray_Better(nums, k) << endl;
    cout << "Find the length of SubArray with sum <= k : " << s.lengthOfSubarray_Optimal(nums, k) << endl;

    return 0;
}