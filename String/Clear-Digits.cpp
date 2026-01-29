#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isInt(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    string clearDigits(string s)
    {
        string ans;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (isInt(s[i]))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while (st.size() != 0)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "abg3";
    cout << "Clear Digits : " << s.clearDigits(str) << endl;
    return 0;
}