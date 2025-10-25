#include <iostream>
using namespace std;
class Solution
{
public:
    long long countSubarrays_Brute(vector<int> &nums, int k)
    {
        long long cnt = 0;
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int point = 0;
            for (int j = i; j < n; j++)
            {
                if (maxElem == nums[j])
                    point++;
                if (point >= k)
                {
                    cnt += n - j;
                    break;
                }
            }
        }
        return cnt;
    }

    long long countSubarrays(vector<int> &nums, int k, int left = 0)
    {
        long maxi = *max_element(nums.begin(), nums.end()), maxiOccurence = 0, res = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == maxi)
            {
                ++maxiOccurence;
            }
            while (maxiOccurence == k)
            {
                if (nums[left] == maxi)
                {
                    --maxiOccurence;
                }
                left++;
            }
            res += left;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    cout << "Count Subarrays Where Max Element Appears at Least K Times : " << s.countSubarrays_Brute(nums, k) << endl;
    cout << "Count Subarrays Where Max Element Appears at Least K Times : " << s.countSubarrays_Optimal(nums, k) << endl;

    return 0;
}