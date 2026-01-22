#include <iostream>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        string ans;
        for (auto ch : s)
        {
            ans += tolower(ch);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "Hello";
    cout << "To Lower Case : " << s.toLowerCase(str) << endl;
    return 0;
}