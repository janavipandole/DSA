#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    // Brute force solution
    int countCompleteSubarrays_Brute(vector<int> &nums)
    {
        set<int> s;
        int cnt = 0;
        for (auto num : nums)
            s.insert(num);

        for (int i = 0; i < nums.size(); i++)
        {
            set<int> ch;
            for (int j = i; j < nums.size(); j++)
            {
                ch.insert(nums[j]);
                if (ch.size() == s.size()) cnt++;
            }
        }
        return cnt;
    }

    // Optimal force solution
    int countCompleteSubarrays_Optimal(vector<int> &nums)
    {
        bool found[2001]{false};
        int distinctTotal = 0;

        for (auto num : nums)
        {
            if (!found[num])
            {
                found[num] = true;
                distinctTotal++;
            }
        }

        int result = 0;
        int count[2001]{0};
        int begin = 0;
        int distinct = 0;

        for (auto num : nums)
        {
            if (count[num]++ == 0)distinct++;

            while (count[nums[begin]] > 1) count[nums[begin++]]--;

            if (distinct == distinctTotal) result += begin + 1;
        }

        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 1, 2, 2};

    cout << "Count Complete Subarrays in an Array : " << s.countCompleteSubarrays_Brute(nums) << endl;
    cout << "Count Complete Subarrays in an Array : " << s.countCompleteSubarrays_Optimal(nums) << endl;

    return 0;
}