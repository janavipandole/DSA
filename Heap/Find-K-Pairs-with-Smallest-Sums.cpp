#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans(k);
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                maxHeap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                if (maxHeap.size() > k)
                {
                    maxHeap.pop();
                }
            }
        }

        while (maxHeap.size() > 0)
        {
            ans[--k] = maxHeap.top().second;
            maxHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {0, 0, 0, 0, 0}, nums2 = {-3, 22, 35, 56, 76};
    int k = 22;
    vector<vector<int>> ans = s.kSmallestPairs(nums1, nums2, k);
    cout << "Find K Pairs with Smallest Sums : " << endl;
    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}