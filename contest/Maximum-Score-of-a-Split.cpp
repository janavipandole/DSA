#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    long long maximumScore(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = LLONG_MIN;

        vector<long long> prefixSum(n);
        vector<int> suffixMin(n);

        // prefix sum
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // suffixMin[i] = min(nums[i+1 ... n-1])
        suffixMin[n - 2] = nums[n - 1];
        for (int i = n - 3; i >= 0; i--)
        {
            suffixMin[i] = min(nums[i + 1], suffixMin[i + 1]);
        }

        // compute answer (i must stop at n-2)
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, prefixSum[i] - suffixMin[i]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,1};
    cout << "Maximum Score of a Split : " << s.maximumScore(nums) << endl;
}
