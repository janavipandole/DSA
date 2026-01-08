#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int ans1 = 0, ans2 = 0;
        for (int num : nums)
        {
            hash[num]++;
        }
        for (auto &[val, key] : hash)
        {
            ans1 += key / 2;
        }
        ans2 = (nums.size() - (ans1 * 2));
        return {ans1, ans2};
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 2, 1, 3, 2, 2};
    cout << "Maximum Number of Pairs in Array : " << endl;
    vector<int> ans = s.numberOfPairs(nums);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}