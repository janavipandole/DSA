#include <iostream>
using namespace std;
class Solution
{
public:
    long long countSubarrays_Brute(vector<int> &nums, int k)
    {
        int maxElem = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxElem)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= k)
                {
                    cnt += nums.size() - j ;
                    break;
                }
            }
        }
        return cnt;
    }

};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    cout << "Count Subarrays Where Max Element Appears at Least K Times : " << s.countSubarrays(nums, k) << endl;
    return 0;
}