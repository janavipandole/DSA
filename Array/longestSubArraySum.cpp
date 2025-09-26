#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int subArraySumBrute1(vector<int> &nums, int k)
    {
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                if (sum == k)
                {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }

    int subArraySumBrute2(vector<int> &nums, int k)
    {
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }

    int subArraySumBetter(vector<int> &nums, int k)
    {
        unordered_map<long long, int> m;
        int maxLength = 0;
        int sum = 0;
        // {1, 2, 3, 1, 1, 0, 1, 0, 1};
        m[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum - k;

            if (m.find(rem) != m.end())
            {
                int idx = i - m[rem];
                maxLength = max(maxLength, idx);
            }

            if (m.find(sum) == m.end())
            {
                m[sum] = i;
            }
        }
        return maxLength;
    }
    // if array contain only 0 and postive digits
    int subArraySumOptimal(vector<int> &nums, int k)
    {
        int maxLength = 0;
        int i = 0, sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            while (i < j && sum > k)
            {
                sum -= nums[i];
                i++;
            }
            sum += nums[j];

            if (sum == k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
        return maxLength;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1, 1, 0, 1, 0, 1};
    cout << "sub Array Sum : " << s.subArraySumBrute1(nums, 4) << endl;
    cout << "sub Array Sum : " << s.subArraySumBrute2(nums, 4) << endl;
    cout << "sub Array Sum : " << s.subArraySumBetter(nums, 4) << endl;
    cout << "sub Array Sum : " << s.subArraySumOptimal(nums, 4) << endl;
    return 0;
}