#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<int> minCosts(vector<int> &cost)
    {
        vector<int> ans;
        int val = cost[0];
        ans.push_back(val);
        for (int i = 1; i < cost.size(); i++)
        {
            val = min(val, cost[i]);
            ans.push_back(val);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {5, 3, 4, 1, 3, 2};
    cout << "Minimum Cost to Reach Every Position : " << endl;
    vector<int> ans = s.minCosts(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}