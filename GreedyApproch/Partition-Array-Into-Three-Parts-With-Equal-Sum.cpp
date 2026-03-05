#include <iostream>
using namespace std;
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if (sum % 3 != 0) return false;
        sum /= 3;
        int count = 0, runingSum = 0;

        for (int num : nums)
        {
            runingSum += num;

            if (runingSum == sum)
            {
                count++;
                runingSum = 0;
            }
        }

        return count >= 3;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {18, 12, -18, 18, -19, -1, 10, 10};
    cout << "Partition Array Into Three Parts With Equal Sum : " << s.canThreePartsEqualSum(nums) << endl;
    return 0;
}