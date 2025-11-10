#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            maxHeap.push({abs(arr[i] - x), arr[i]});
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        while (maxHeap.size() > 0)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    cout << "Find K Closest Elements : " << endl;
    vector<int> ans = s.findClosestElements(nums, k, x);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}