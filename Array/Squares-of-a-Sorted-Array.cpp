#include <iostream>
using namespace std;
vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> ans;
    for (auto num : nums)
    {
        ans.push_back(num * num);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ans = sortedSquares(nums);
    for(auto num : ans) cout<<num<<" ";
    cout<<endl;
    return 0;
}