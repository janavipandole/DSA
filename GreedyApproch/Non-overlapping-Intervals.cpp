#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1]; // Sort by end time
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        int compare = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (compare <= intervals[i][0]) // Non-overlapping condition
            {
                cnt++;
                compare = intervals[i][1];
            }
        }

        return n - cnt;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout<<"Non-overlapping Intervals : " << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
