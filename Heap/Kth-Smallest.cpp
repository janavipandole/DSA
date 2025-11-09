#include <iostream>
using namespace std;
class Solution
{
public:
    int kthSmallest(vector<int> &nums, int k)
    {
        priority_queue<int> maxHeap;

        for (int i = 0; i < nums.size(); i++)
        {
            maxHeap.push(nums[i]);
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
int main()
{
    Solution s;
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    cout << "Kth Smallest : " << s.kthSmallest(arr, k) << endl;
    return 0;
}