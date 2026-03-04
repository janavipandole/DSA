#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> ans(s.size(), INT_MAX);
        vector<int> nums;
        for (int i = 0; i < s.size(); i++)
        {
            if (c == s[i]) nums.push_back(i);
        }
        for (int i = 0; i < s.size(); i++)
        {
            int index = i;
            for (int num : nums)
            {
                ans[i] = min(abs(index - num), ans[i]);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "loveleetcode";
    char ch = 'e';
    cout << "Shortest Distance to a Character : " << endl;
    vector<int> nums = s.shortestToChar(str, ch);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}