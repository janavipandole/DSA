#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            int val = nums[2 * i + 1];
            int freq = nums[2 * i];
            for (int j = 0; j < freq; j++)
            {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4,2,5};
    cout << "Decompress Run-Length Encoded List : " << endl;
    vector<int> ans = s.decompressRLElist(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}