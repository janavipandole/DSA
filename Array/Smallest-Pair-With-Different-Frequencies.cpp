#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> minDistinctFreqPair(vector<int> &nums)
    {
        if (nums.size() <= 2) return {-1, -1};
        
        map<int, int> hash;
        for (auto num : nums)
        {
            hash[num]++;
        }
        int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
        for (auto &[num, count] : hash)
        {
            if (cnt1 == 0 && num1 == -1)
            {
                cnt1 = count;
                num1 = num;
            }
            else if (cnt1 != count)
            {
                cnt2 = count;
                num2 = num;
                break;
            }
        }
        if(num2 == -1) return {-1, -1};
        return {num1, num2};
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3, 4};
    cout << "Smallest Pair With Different Frequencies : " << endl;
    vector<int> ans = s.minDistinctFreqPair(nums);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}