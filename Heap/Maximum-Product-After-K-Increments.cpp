#include <iostream>
using namespace std;
class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        const long long MOD = 1'000'000'007;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums)
            minHeap.push(num);

        while (k--)
        {
            int x = minHeap.top() + 1;
            minHeap.pop();
            minHeap.push(x);
        }

        long long ans = 1;

        while (minHeap.size() > 0)
        {
            ans =  (ans * minHeap.top()) % MOD;
            minHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {24, 5, 64, 53, 26, 38};
    int k = 54;
    cout << "Maximum Product After K Increments : " << s.maximumProduct(nums, k) << endl;

    return 0;
}