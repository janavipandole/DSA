#include <iostream>
using namespace std;
// Solution 1
vector<int> rowAndMaximumOnes1(vector<vector<int>> &nums)
{
    vector<int> ans(2);
    int cnt_max = -1;
    int m = nums[0].size();
    for (int i = 0; i < nums.size(); i++)
    {
        sort(nums[i].begin(), nums[i].end());
        auto it = lower_bound(nums[i].begin(), nums[i].end(), 1);
        int cnt_one = m - (it - nums[i].begin());
        if (cnt_one > cnt_max)
        {
            cnt_max = cnt_one;
            ans[0] = i;
            ans[1] = cnt_max;
        }
    }
    return ans;
}
// solution 2
vector<int> rowAndMaximumOnes2(vector<vector<int>> &mat)
{
    vector<int> ans(2, 0);
    for (int i = 0; i < mat.size(); i++)
    {
        int tmp = 0;
        for (int j = 0; j < mat[i].size(); j++)
            tmp += mat[i][j];
        if (tmp > ans[1])
        {
            ans[0] = i;
            ans[1] = tmp;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> nums = {{1, 0, 0}};
    vector<int> ans = rowAndMaximumOnes2(nums);
    cout << "row And Maximum Ones : " << endl;
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}