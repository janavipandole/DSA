#include <iostream>
using namespace std;
class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (n % (i + 1) == 0)
            {
                sum += (nums[i] * nums[i]);
            }
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 7, 1, 19, 18, 3};
    cout << "Sum of Squares of Special Elements : " << s.sumOfSquares(nums) << endl;
    return 0;
}