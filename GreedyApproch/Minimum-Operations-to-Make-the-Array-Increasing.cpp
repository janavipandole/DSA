#include <iostream>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        if (nums.size() == 1 || nums.size() == 0) return 0;
        int sum = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                sum += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1, 1, 1};
    vector<int> nums2 = {1, 5, 2, 4, 1};
    vector<int> nums3 = {8};
    cout << "Minimum Operations to Make the Array Increasing : " << s.minOperations(nums1) << endl;
    cout << "Minimum Operations to Make the Array Increasing : " << s.minOperations(nums2) << endl;
    cout << "Minimum Operations to Make the Array Increasing : " << s.minOperations(nums3) << endl;

    return 0;
}