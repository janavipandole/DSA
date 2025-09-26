#include <iostream>
using namespace std;
class Solution
{
public:
    int smallestAbsent(vector<int> &nums)
    {
        vector<bool> seen(107, false);
        int sum = 0;
        for (int x : nums)
        {
            if (x >= 1)
                seen[x] = true;
            sum += x;
        }

        for (int ans = 1;; ans++)
        {
            if (seen[ans] || ans * (int)nums.size() <= sum)
            {
                continue;
            }
            return ans;
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-1, 1, 2};
    cout << "Smallest Absent Positive Greater Than Average : " << s.smallestAbsent(nums) << endl;
    return 0;
}