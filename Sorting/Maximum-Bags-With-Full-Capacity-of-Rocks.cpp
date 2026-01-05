#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = rocks.size();
        int ans = 0;

        vector<int> need;
        for (int i = 0; i < n; i++)
        {
            need.push_back(capacity[i] - rocks[i]);
        }

        sort(need.begin(), need.end());
        for (int i = 0; i < n; i++)
        {
            if (need[i] == 0)
            {
                ans++;
            }
            else if (additionalRocks >= need[i])
            {
                additionalRocks -= need[i];
                ans++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> capacity = {4, 18, 91, 49, 51, 45, 58, 54, 47, 91, 90, 20, 85, 20, 90, 49, 10, 84, 59, 29, 40, 9, 100, 1, 64, 71, 30, 46, 91}, rocks = {14, 13, 16, 44, 8, 20, 51, 15, 46, 76, 51, 20, 77, 13, 14, 35, 6, 34, 34, 13, 3, 8, 1, 1, 61, 5, 2, 15, 18};
    int additionalRocks = 77;
    cout << "Maximum Bags With Full Capacity of Rocks : " << s.maximumBags(capacity, rocks, additionalRocks) << endl;
    return 0;
}