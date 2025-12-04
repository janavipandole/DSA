#include <iostream>
using namespace std;
class Solution {
public:
    bool isAllEqual(vector<int> &nums)
    {
        if(nums.size() == 1) return false;
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1]) return false;
        }
        return true;
    }
    int countElements(vector<int>& nums, int k) {
      if (nums.size() == 0 || isAllEqual(nums)) return 0;

      if(k == 0) return nums.size();

        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] && nums.size() - i >= k) cnt++;
        }

        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 1, 2};
    cout << "Count Elements With at Least K Greater Values : " << s.countElements(nums, 1) << endl;
    return 0;
}