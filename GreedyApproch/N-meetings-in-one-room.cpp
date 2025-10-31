#include <iostream>
using namespace std;
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        vector<pair<int, int>> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp.push_back({end[i], start[i]});
        }

        sort(mpp.begin(), mpp.end());
        int cnt = 1;

        int compare = mpp[0].first;
        for (int i = 1; i < n; i++)
        {

            if (compare < mpp[i].second)
            {
                cnt++;
                compare = mpp[i].first;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> start = {10, 12, 20}, end = {20, 25, 30};
    cout << "N meetings in one room : " << s.maxMeetings(start, end) << endl;
    return 0;
}