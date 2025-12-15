#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        unordered_set<int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp.insert(nums[i]);
            if (nums[i] > 9)
            {
                string num = to_string(nums[i]);
                reverse(num.begin(), num.end());
                mpp.insert(stoi(num));
            }
        }
        return mpp.size();
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 13, 10, 12, 31};
    cout << "Count Number of Distinct Integers After Reverse Operations : " << s.countDistinctIntegers(nums) << endl;
    return 0;
}