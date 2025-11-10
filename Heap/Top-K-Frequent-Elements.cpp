#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int num : nums)
        {
            mpp[num]++;
        }

        for (auto &[key, val] : mpp)
        {
            minHeap.push({val, key});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        while (minHeap.size() > 0)
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k = 2;
    cout << "Top K Frequent Elements :" << endl;
    vector<int> ans = s.topKFrequent(nums, k);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}