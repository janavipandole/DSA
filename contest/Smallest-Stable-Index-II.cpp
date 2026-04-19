#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffMin(n);
        prefixMax[0] = nums[0];
        suffMin[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (prefixMax[i] - suffMin[i] <= k)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;
    cout << "Smallest Stable Index II : " << s.firstStableIndex(nums, k) << endl;
    return 0;
}