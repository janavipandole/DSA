#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays_Brute(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % 2 != 0) cnt++;
                if (cnt > k) break;
                if (cnt == k) ans++;
                
            }
        }
        return ans;
    }

    //Optiaml solution
    int helper(vector<int> &nums, int goal)
    {
        if (goal < 0) return 0;
        int cnt = 0, end = 0, st = 0, n = nums.size(), sum = 0;
        while (end < n)
        {
            sum += nums[end]%2;

            while (sum > goal && st <= end)
            {
                sum -= nums[st]%2;
                st++;
            }

            if (sum <= goal) cnt += end - st + 1;

            end++;
        }
        return cnt;
    }
    int numberOfSubarrays_Optimal(vector<int> &nums, int k)
    {
        return helper(nums,k) - helper(nums, k-1);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout << "Count Number of Nice Subarrays : " << s.numberOfSubarrays_Brute(nums, k) << endl;
    cout << "Count Number of Nice Subarrays : " << s.numberOfSubarrays_Optimal(nums, k) << endl;
    return 0;
}