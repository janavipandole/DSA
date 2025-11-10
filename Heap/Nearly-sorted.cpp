#include <iostream>
using namespace std;
class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int index = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            minHeap.push(arr[i]);
            if (minHeap.size() > k)
            {
                arr[index] = minHeap.top();
                minHeap.pop();
                index++;
            }
        }

        while (minHeap.size() > 0)
        {
            arr[index] = minHeap.top();
            minHeap.pop();
            index++;
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 4};
    int k = 2;
    cout << "Nearly sorted : " << endl;
    s.nearlySorted(nums, k);
    for (auto val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}