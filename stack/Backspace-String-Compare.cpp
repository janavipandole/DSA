#include <iostream>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        if (s == t)
            return true;
        stack<char> st1;
        stack<char> st2;

        for (auto ch : s)
        {
            if (!st1.empty() && ch == '#')
                st1.pop();
            else if (ch != '#')
                st1.push(ch);
        }

        for (auto ch : t)
        {
            if (!st2.empty() && ch == '#')
                st2.pop();
            else if (ch != '#')
                st2.push(ch);
        }

        if (st1.size() != st2.size())
            return false;

        while (st1.size() > 0 && st2.size() > 0)
        {
            if (st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }
        return true;
    }
};
int main()
{
    Solution s;
    string str = "y#fo##f", t = "y#f#o##f";
    cout << "Backspace String Compare : " << s.backspaceCompare(str, t) << endl;
    return 0;
}