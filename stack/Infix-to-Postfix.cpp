#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    string infixToPostfix(string &s)
    {
        map<char, int> priority = {
            {'^', 3},
            {'*', 2},
            {'/', 2},
            {'+', 1},
            {'-', 1},
        };

        int i = 0, n = s.size();
        string ans;
        stack<char> st;
        while (i < n)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                ans += s[i];
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && st.top() != '(' &&
                       (priority[s[i]] < priority[st.top()] || (priority[s[i]] == priority[st.top()] && s[i] != '^')))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "(a+b)*(c+d)";
    cout << "Infix to Postfix : " << s.infixToPostfix(str) << endl;

    return 0;
}