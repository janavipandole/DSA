#include <iostream>
#include <vector>
using namespace std;

vector<int> searchInTwoDArray(vector<vector<int>> &nums, int tar)
{
    vector<int> ans;
    int col = nums[0].size();
    int row = nums.size();
    int st = 0;
    int end = col - 1;

    while (st <= row || end >= 0)
    {
        if (tar == nums[st][end])
        {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }

        if (tar < nums[st][end])
        {
            end--;
        }
        else
        {
            st++;
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 20}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int tar = 14;
    vector<int> ans = searchInTwoDArray(nums, tar);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}