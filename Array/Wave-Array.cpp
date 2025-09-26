#include <iostream>
using namespace std;
class Solution
{
public:
    void sortInWave(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() + 1; i += 2)
        {
            swap(nums[i], nums[i + 1]);
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 4, 7, 8, 9, 10};
    s.sortInWave(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}