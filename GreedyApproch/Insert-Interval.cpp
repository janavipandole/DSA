#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        if (intervals.size() == 0) return {{newInterval[0], newInterval[1]}};

        vector<vector<int>> ans;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    cout << "Insert Interval : " << endl;
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for (auto num : ans)
    {
        cout << num[0] << " " << num[1] << endl;
    }
    return 0;
}