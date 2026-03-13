#include <iostream>
#include <stack>
using namespace std;
// User function Template for C++
class Solution
{
public:
    string postToInfix(string &exp)
    {
        stack<string> ans;
        int i = 0, n = exp.length();
        while (i < n)
        {
            if (isalnum(exp[i]))
            {
                string s(1, exp[i]); // char → string
                ans.push(s);
            }
            else
            {
                string s1 = ans.top();
                ans.pop();

                string s2 = ans.top();
                ans.pop();

                string newS = "(" + s2 + string(1, exp[i]) + s1 + ")";
                ans.push(newS);
            }
            i++;
        }
        return ans.top();
    }
};
int main()
{
    Solution s;
    string str = "ab*c+";
    cout << "Postfix to Infix Conversion : " << s.postToInfix(str) << endl;

    return 0;
}