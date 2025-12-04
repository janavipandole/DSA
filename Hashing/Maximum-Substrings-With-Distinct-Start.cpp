#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxDistinct(string s)
    {
        unordered_set<char> hash(s.begin(), s.end());
        return hash.size();
    }
};
int main()
{
    Solution s;
    string str = "abab";
    cout << "Maximum Substrings With Distinct Start : " << s.maxDistinct(str) << endl;
    return 0;
}