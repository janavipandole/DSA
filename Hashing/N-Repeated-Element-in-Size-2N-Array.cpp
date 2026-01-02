#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int repeatedNTimesBrute(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }

        for (auto &[val, key] : hash)
        {
            if (key == nums.size() / 2)
            {
                ans = val;
            }
        }
        return ans;
    }

    int repeatedNTimesOptimal(vector<int> &nums)
    {

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
            {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};
int main()
{
    Solution s;
    vector<int> nums = {5, 1, 5, 2, 5, 3, 5, 4};
    cout << "N-Repeated Element in Size 2N Array : " << s.repeatedNTimesOptimal(nums) << endl;
    return 0;
}