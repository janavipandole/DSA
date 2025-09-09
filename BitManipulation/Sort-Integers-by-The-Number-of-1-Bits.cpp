#include <iostream>
#include <set>
using namespace std;
int count(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}
vector<int> sortByBits(vector<int> &nums)
{
    vector<pair<int, int>> mpp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp.push_back({count(nums[i]), nums[i]});
    }
    sort(mpp.begin(), mpp.end());
    for (auto val : mpp)
    {
        // cout<<val.first<<" "<<val.second<<endl;
        ans.push_back(val.second);
    }
    return ans;
}
int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7,8};
    cout << "Sort Integers by The Number of 1 Bits : " << endl;
    vector<int> ans = sortByBits(nums);
    for (auto n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}