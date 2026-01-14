#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 4, 2, 4, 3};
    cout << "Number of Unequal Triplets in Array  : " << s.unequalTriplets(nums) << endl;

    return 0;
}