#include <iostream>
#include <stack>
using namespace std;
// User function Template for C++
class Solution
{
public:
    string postToPre(string post_exp)
    {
        stack<string> ans;
        int i = 0, n = post_exp.length();
        while (i < n)
        {
            if (isalnum(post_exp[i]))
            {
                string s(1, post_exp[i]); // char → string
                ans.push(s);
            }
            else
            {
                string s1 = ans.top();
                ans.pop();

                string s2 = ans.top();
                ans.pop();

                string newS = string(1, post_exp[i]) + s2 + s1;
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
    cout << "Postfix to Prefix Conversion : " << s.postToPre(str) << endl;

    return 0;
}