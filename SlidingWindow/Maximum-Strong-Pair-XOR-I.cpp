#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int maxXOR = 0;
        int val = 0, mini = 0, XOR = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            for (int j = i; j < nums.size(); j++)
            {
                val = abs(nums[j] - nums[i]);
                mini = min(nums[j], nums[i]);
                if (val <= mini)
                {
                    XOR = nums[i] ^ nums[j];
                }
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
    cout << "Maximum Strong Pair XOR I : " << s.maximumStrongPairXor(nums) << endl;
    return 0;
}