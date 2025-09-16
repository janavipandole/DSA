// Give an array of string of size n print unique strings in lexiogaphical order with their frequency
// n <= 10^5
// S.length <= 100
#include <iostream>
#include <map>
using namespace std;

vector<pair<string, int>> getString(vector<string> &strs)
{
    map<string, int> m;
    vector<pair<string, int>> ans;
    for (auto str : strs)
    {
        m[str]++;
    }

    for (auto &[key, val] : m)
    {
        ans.push_back({key, val});
    }
    return ans;
}

int main()
{
    vector<string> strs = {"abc", "def", "abc", "ghj", "ghj", "ghj", "jkl", "abc"};

    vector<pair<string, int>> ans = getString(strs);
    for (auto &[key, val] : ans)
    {
        cout << key << " " << val << endl;
    }
    return 0;
}