#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.size()) return "0";

        string ans = "";
        stack<int> s;
    
        for (auto ch : num)
        {
            while (!s.empty() && k > 0 && s.top() > (ch - '0'))
            {
                s.pop();
                k--;
            }

            s.push(ch - '0');
        }

        while (!s.empty())
        {
            if (k > 0)
            {
                s.pop();
                k--;
            }
            else
            {
                ans += s.top() + '0';
                s.pop();
            }
        }

        while (!ans.empty() && ans.back() == '0') ans.pop_back();

        if (ans.empty()) return "0";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    string num = "10200";
    int k = 1;
    cout << "Remove k Digit : " << s.removeKdigits(num, k) << endl;
    return 0;
}