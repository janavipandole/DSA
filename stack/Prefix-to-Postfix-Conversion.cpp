#include <iostream>
#include <stack>
using namespace std;
// User function Template for C++

class Solution
{
public:
    string preToPost(string pre_exp)
    {
        stack<string> ans;
        int i = pre_exp.size() - 1;
        while (i >= 0)
        {
            if (isalnum(pre_exp[i]))
            {
                string s(1, pre_exp[i]); // char → string
                ans.push(s);
            }
            else
            {
                string s1 = ans.top();
                ans.pop();

                string s2 = ans.top();
                ans.pop();

                string newS = s1 + s2 + string(1, pre_exp[i]);
                ans.push(newS);
            }
            i--;
        }
        return ans.top();
    }
};
int main()
{
    Solution s;
    string str = "*+AB-CD";
    cout << "Prefix to Infix Conversion : " << s.preToPost(str) << endl;
    return 0;
}