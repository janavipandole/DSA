#include <iostream>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;
    cout << "Count Equal and Divisible Pairs in an Array : " << s.countPairs(nums, k)<< endl;
    return 0;
}