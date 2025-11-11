#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        
        for (int i = 0; i < nums.size(); i++) ans[i] = nums[i];

        sort(ans.begin(), ans.end());

        for(int i=0 ; i<ans.size()-1;i+=2) swap(ans[i] , ans[i+1]);

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 4, 5};
    cout << "Minimum Number Game : " << endl;
    vector<int> ans = s.numberGame(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}