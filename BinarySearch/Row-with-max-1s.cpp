#include <iostream>
using namespace std;

int rowWithMax1s(vector<vector<int>> &nums)
{
    int cnt_max = -1;
    int index = -1;
    int m = nums[0].size();
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = lower_bound(nums[i].begin(), nums[i].end(), 1);
        int cnt_one = m - (it - nums[i].begin());
        if (cnt_one > cnt_max)
        {
            cnt_max = cnt_one;
            index = i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> nums = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << "rowWithMax1s : " << rowWithMax1s(nums) << endl;
    return 0;
}