#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minimumPrefixLength(vector<int> &nums)
    {
        int index = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                index = i;
            }
        }
        if (index != -1)
        {
            return index + 1;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, -1, 2, 3, 3, 4, 5};
    cout << "Minimum Prefix Removal to Make Array Strictly Increasing : " << s.minimumPrefixLength(nums) << endl;
}
