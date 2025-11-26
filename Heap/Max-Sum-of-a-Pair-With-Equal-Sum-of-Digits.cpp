#include <iostream>
using namespace std;
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {

        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }

            maxHeap.push({sum, nums[i]});
        }

        int ans = -1;
        while (maxHeap.size() > 1)
        {
            int sum1 = maxHeap.top().first;
            int num1 = maxHeap.top().second;

            maxHeap.pop();
            if (sum1 == maxHeap.top().first)
            {
                ans = max(ans, num1 + maxHeap.top().second);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {10, 12, 19, 14};

    cout << "Max Sum of a Pair With Equal Sum of Digits : " << s.maximumSum(nums) << endl;
    return 0;
}