#include <iostream>
using namespace std;
class Solution
{
public:
vector<int> removeDuplicates(vector<int> &arr)
{
    vector<int> ans;
    int k = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (ans.empty() || ans.back() != arr[i])
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
}
int main()
{
    Solution s;
    vector<int> nums = {1,  2,  2,  3, 4,  5, 6, 6};
    cout << "Remove Duplicates Sorted Array : " << endl;
    vector<int> ans = s.removeDuplicates(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}