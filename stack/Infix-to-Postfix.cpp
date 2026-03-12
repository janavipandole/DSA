#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int priority(char op)
    {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }
    string infixToPostfix(string &s)
    {
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
                       (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && s[i] != '^')))
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
    string str = "a*(b+c)/d";
    cout << "Infix to Postfix : " << s.infixToPostfix(str) << endl;

    return 0;
}