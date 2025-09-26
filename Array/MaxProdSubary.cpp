#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxPodSubAryBrute(vector<int> &nums)
    {
        int maxProduct = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            int maxCurrProd = 1;
            for (int j = i; j < nums.size(); j++)
            {
                maxCurrProd = maxCurrProd * nums[j];
                maxProduct = max(maxProduct, maxCurrProd);
            }
        }
        return maxProduct;
    }

    int maxProductOptimal(vector<int> &nums)
    {
        int perfix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (perfix == 0)
                perfix = 1;
            if (suffix == 0)
                suffix = 1;

            perfix = perfix * nums[i];
            suffix = suffix * nums[nums.size() - 1 - i];
            maxProduct = max(maxProduct, suffix);
            maxProduct = max(maxProduct, perfix);
        }
        return maxProduct;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Max Product Subarray (Brute Force): " << s.maxPodSubAryBrute(nums) << endl;
    cout << "Max Product Subarray (Optimal): " << s.maxProductOptimal(nums) << endl;
    return 0;
}