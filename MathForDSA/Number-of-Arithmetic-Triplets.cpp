#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - nums[i] == diff)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        if (nums[k] - nums[j] == diff) count++;
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
    vector<int> nums = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    cout << "Number of Arithmetic Triplets : " << s.arithmeticTriplets(nums, diff) << endl;
    return 0;
}