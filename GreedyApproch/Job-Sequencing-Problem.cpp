#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        int n = profit.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort by profit descending
        sort(jobs.rbegin(), jobs.rend());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slot(maxDeadline + 1, -1);

        int cnt = 0;
        int maxProfit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = jobs[i].second; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    cnt++;
                    maxProfit += jobs[i].first;
                    break;
                }
            }
        }

        return {cnt, maxProfit};
    }
};

int main()
{
    Solution s;
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};

    cout << "Job Sequencing Problem:\n";
    vector<int> ans = s.jobSequencing(deadline, profit);
    cout << "Jobs done: " << ans[0] << "\n";
    cout << "Max Profit: " << ans[1] << endl;

    return 0;
}
