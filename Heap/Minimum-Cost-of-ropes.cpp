#include <iostream>
using namespace std;
class Solution
{
public:
    int minCost(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

        int ans = 0;

        while (minHeap.size() > 1)
        {
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();

            int sum = a + b;
            ans += sum;
            minHeap.push(sum);
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 2, 7, 6, 9};
    cout << "Minimum Cost of ropes : " << s.minCost(nums) << endl;
    return 0;
}