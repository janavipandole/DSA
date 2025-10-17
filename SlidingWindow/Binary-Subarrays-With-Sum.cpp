#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Brute force solution
    int numSubarraysWithSum_Brute(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k) cnt++;
                if (sum > k) break;
            }
        }
        return cnt;
    }
    // Better Approch
    int numSubarraysWithSum_Better(vector<int> &nums, int k)
    {
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int remove = sum - k;
            cnt += m[remove];
            m[sum] += 1;
        }
        return cnt;
    }
    // Optimal Approch
    int helper(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int cnt = 0, end = 0, st = 0, n = nums.size(), sum = 0;
        while (end < n)
        {
            sum += nums[end];

            while (sum > goal && st <= end)
            {
                sum -= nums[st];
                st++;
            }

            if (sum <= goal) cnt += end - st + 1;

            end++;
        }
        return cnt;
    }

    int numSubarraysWithSum_Optimal(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << "Binary Subarrays With Sum : " << s.numSubarraysWithSum_Brute(nums, goal) << endl;
    cout << "Binary Subarrays With Sum : " << s.numSubarraysWithSum_Better(nums, goal) << endl;
    cout << "Binary Subarrays With Sum : " << s.numSubarraysWithSum_Optimal(nums, goal) << endl;

    return 0;
}