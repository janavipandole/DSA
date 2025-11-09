#include <iostream>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "Kth Largest Element in an Array : " << s.findKthLargest(nums, k) << endl;
    return 0;
}