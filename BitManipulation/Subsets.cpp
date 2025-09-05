#include <iostream>
using namespace std;
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();
    int numOfSubsets = 1 << n;
    for (int num = 0; num < numOfSubsets; num++)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if ((num & (1 << i)))
            {
                ans.push_back(nums[i]);
            }
        }
        result.push_back(ans);
    }
    return result;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (auto num : ans)
    {
        cout<<"[";
        for (auto n : num)
        {
            cout << n << " ";
        }
        cout<<"]" << endl;
    }
    return 0;
}