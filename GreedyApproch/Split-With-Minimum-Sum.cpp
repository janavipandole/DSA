#include <iostream>
using namespace std;
class Solution
{
public:
    int splitNum(int num)
    {
        vector<int> nums;
        while (num > 0)
        {
            nums.push_back(num % 10);
            num /= 10;
        }
        sort(nums.begin(), nums.end());

        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0) num1 = num1 * 10 + nums[i];
            else num2 = num2 * 10 + nums[i];
        }
        return num1 + num2;
    }
};
int main()
{
    Solution s;
    int num = 4325;
    cout << "Split With Minimum Sum : " << s.splitNum(num) << endl;
    return 0;
}