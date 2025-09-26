#include <iostream>
using namespace std;
class Solution
{
public:
    long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k)
    {
        vector<int> num;
        for (int i = 0; i < grid.size(); i++)
        {
            sort(grid[i].rbegin(), grid[i].rend());
            int cnt = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (cnt == limits[i])
                    break;
                num.push_back(grid[i][j]);
                cnt++;
            }
        }
        sort(num.rbegin(), num.rend());
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += num[i];
        }

        return sum;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    vector<int> limits = {1, 2};
    int k = 2;
    cout << "Maximum Sum With at Most K Elements : " << s.maxSum(grid, limits, k) << endl;
    return 0;
}