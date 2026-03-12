#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int priority(char op)
    {
        if (op == '^')
            return 3;
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return -1;
    }
    string infixToPrefix(string &s)
    {
        int n = s.size();
        int i = 0;
        string ans;
        stack<char> st;
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }

        while (i < n)
        {
            if (isalnum(s[i]))
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
                if (s[i] == '^')
                {
                    while (!st.empty() && st.top() != '(' && (priority(s[i]) <= priority(st.top())))
                    {
                        ans += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() && st.top() != '(' && (priority(s[i]) < priority(st.top())))
                    {
                        ans += st.top();
                        st.pop();
                    }
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix To Prefix : " << s.infixToPrefix(str) << endl;
    return 0;
}