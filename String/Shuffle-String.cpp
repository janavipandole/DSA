#include <iostream>
using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        vector<pair<int, char>> hash;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            hash.push_back({indices[i], s[i]});
        }
        sort(hash.begin(), hash.end());
        string ans;
        for (int i = 0; i < n; i++)
        {
            ans += hash[i].second;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    cout << "Shuffle String : " << s.restoreString(str, indices) << endl;
    return 0;
}