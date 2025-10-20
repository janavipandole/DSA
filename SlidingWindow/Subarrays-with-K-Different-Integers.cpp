#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int subarraysWithKDistinct_Brute(vector<int> &nums, int k)
    {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> s;
            for (int j = i; j < nums.size(); j++)
            {
                s.insert(nums[j]);
                if (s.size() == k) cnt++;
                if (s.size() > k) break;
            }
        }
        return cnt;
    }

    int helper(vector<int> &nums, int k)
    {
        if(k == 0) return 0;
        int cnt = 0, end = 0, st = 0;
        unordered_map<int, int> s;

        while (end < nums.size())
        {
            s[nums[end]]++;

            while (s.size() > k)
            {
                s[nums[st]]--;
                if (s[nums[st]] == 0) s.erase(nums[st]);
                st++;
            }
            if (s.size() <= k) cnt += end - st + 1;

            end++;
        }
        return cnt;
    }
    int subarraysWithKDistinct_Optimal(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k-1);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Subarrays with K Different Integers : " << s.subarraysWithKDistinct_Brute(nums, k) << endl;
    cout << "Subarrays with K Different Integers : " << s.subarraysWithKDistinct_Optimal(nums, k) << endl;

    return 0;
}