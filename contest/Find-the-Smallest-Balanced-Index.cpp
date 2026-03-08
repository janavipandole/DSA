#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int smallestBalancedIndex(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = (prefixSum[i - 1] + nums[i - 1]);
        }

        vector<long long> suffixProduct(n, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            suffixProduct[i] = (suffixProduct[i + 1] * nums[i + 1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (suffixProduct[i] == prefixSum[i]) return i;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 8, 2, 2, 5};
    cout << "Find the Smallest Balanced Index : " << s.smallestBalancedIndex(nums) << endl;
    return 0;
}