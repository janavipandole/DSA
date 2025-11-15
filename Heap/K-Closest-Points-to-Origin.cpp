#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> maxHeap;
        vector<vector<int>> ans;
        int dist = 0;
        for (int i = 0; i < points.size(); i++)
        {
            dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({dist, i});

            if (maxHeap.size() > k) maxHeap.pop();
        }

        while (maxHeap.size() > 0)
        {
            int val = maxHeap.top().second;
            ans.push_back(points[val]);
            maxHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    cout << "K Closest Points to Origin : " << endl;
    vector<vector<int>> ans = s.kClosest(points, k);
    for (auto num : ans)
    {
        cout << num[0] << " " << num[1] << endl;
    }
    return 0;
}