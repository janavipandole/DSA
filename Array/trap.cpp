#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void print(vector<int> &nums)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    int trapBrute(vector<int> &nums)
    {
        int maxWater = 0;
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 0; i < n; i++)
        {
            int cnt = nums[i];
            for (int j = 0; j < i; j++)
            {
                cnt = max(cnt, nums[j]);
            }
            left[i] = cnt;
        }
        for (int i = 0; i < n; i++)
        {
            int cnt = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                cnt = max(cnt, nums[j]);
            }
            right[i] = cnt;
        }
        for (int i = 0; i < n; i++)
        {
            int height = min(left[i], right[i]);
            maxWater += height - nums[i];
        }
        return maxWater;
    }

    int trapBetter(vector<int> &nums)
    {
        int maxWater = 0;
        int n = nums.size();
        vector<int> left(n, nums[0]);
        vector<int> right(n, nums[n - 1]);

        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++)
        {
            int height = min(left[i], right[i]);
            int cntWater = height - nums[i];
            maxWater += height - nums[i];
        }
        return maxWater;
    }

    int trapOptimal(vector<int> &nums)
    {
        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int ans = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            leftMax = max(leftMax, nums[left]);
            rightMax = max(rightMax, nums[right]);

            if (leftMax < rightMax)
            {
                ans += leftMax - nums[left];
                left++;
            }
            else
            {
                ans += rightMax - nums[right];
                right--;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 2, 0, 3, 2, 5};
    cout << s.trapBetter(nums) << endl;
    cout << s.trapBrute(nums) << endl;
    cout << s.trapOptimal(nums) << endl;
    return 0;
}