#include <iostream>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        while (a > 0 && b > 0)
        {
            if (a > b)
                a %= b;
            else
                b %= a;
        }
        return a > 0 ? a : b;
    }
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int Max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            Max = max(Max, nums[i]);
            prefixGcd[i] = gcd(Max, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0;
        int j = prefixGcd.size() - 1;
        long long ans = 0;
        while (i < j)
        {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 6, 4};
    cout << "Sum of GCD of Formed Pairs : " << s.gcdSum(nums) << endl;
    return 0;
}