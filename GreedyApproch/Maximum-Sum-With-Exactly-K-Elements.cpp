#include <iostream>
using namespace std;
class Solution
{
public:
    int maximizeSumMethod1(vector<int> &nums, int k)
    {
        int maxElem = *max_element(nums.begin(), nums.end());
        int sum = 0;
        while (k > 0)
        {
            sum += maxElem;
            maxElem++;
            k--;
        }
        return sum;
    }

    int maximizeSumMethod2(vector<int>& nums, int k) {
        int maxElem = *max_element(nums.begin(), nums.end());
        
        return (maxElem + maxElem + k - 1) * k / 2;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    cout << "Maximum Sum With Exactly K Elements  : " << s.maximizeSumMethod1(nums, k) << endl;
    cout << "Maximum Sum With Exactly K Elements  : " << s.maximizeSumMethod2(nums, k) << endl;

    return 0;
}