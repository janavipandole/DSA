#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> findKLargestElement(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> ans(k);

        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        while (minHeap.size() > 0)
        {
            ans[--k] = minHeap.top();
            minHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {11, 5, 12, 9, 44, 17, 2};
    int k = 2;
    cout << "Find k largest elements in an array : " << endl;
    vector<int> ans = s.findKLargestElement(nums, k);
    for (auto an : ans)
    {
        cout << an << " ";
    }
    cout << endl;
    return 0;
}