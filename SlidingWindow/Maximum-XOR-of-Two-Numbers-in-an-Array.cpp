#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int maxXOR = 0;
        int XOR = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                XOR = nums[i] ^ nums[j];
                maxXOR = max(XOR, maxXOR);
            }
        }
        return maxXOR;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Maximum XOR of Two Numbers in an Array : " << s.findMaximumXOR(nums) << endl;
    return 0;
}