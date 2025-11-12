#include <iostream>
using namespace std;
class Solution
{
public:
    int countMajoritySubarraysI(vector<int> &nums, int target)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int countTarget = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] == target)
                {
                    countTarget++;
                }

                if (countTarget * 2 > j - i + 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 2, 3};
    int target = 2;
    cout << "Count Subarrays With Majority Element I : " << s.countMajoritySubarraysI(nums, target) << endl;
    return 0;
}