#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trapBrute(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        vector<int> MinLmRm(n);

        MinLmRm[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            MinLmRm[i] = max(MinLmRm[i - 1], nums[i]);
        }

        MinLmRm[n - 1] = min(MinLmRm[n - 1], nums[n - 1]);
        int Max = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            Max = max(Max, nums[i]);
            MinLmRm[i] = min(MinLmRm[i], Max);
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < MinLmRm[i])
            {
                ans += MinLmRm[i] - nums[i];
            }
        }
        return ans;
    }

    int trapOptimal(vector<int> &nums)
    {
        int total = 0;
        int n = nums.size();

        int l = 0, r = n - 1;
        int LM = 0, RM = 0;
        while (l < r)
        {
            if (nums[l] <= nums[r])
            {
                if(LM > nums[l]) total += LM - nums[l];
                else LM = nums[l];
                l++;
            }else {
                if(RM > nums[r]) total += RM - nums[r];
                else RM = nums[r];
                r--;
            }
        }

        return total;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapping Rain Water : " << s.trapOptimal(nums) << endl;
    return 0;
}