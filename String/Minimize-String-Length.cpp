#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution
{
public:
    int minimizedStringLength(string s)
    {
        unordered_set<char> hash;
        for(auto ch : s) hash.insert(ch);
        return hash.size();
    }
};
int main()
{
    Solution s;
    string str = "aaabc";
    cout << "Minimize String Length : " << s.minimizedStringLength(str) << endl;
    return 0;
}