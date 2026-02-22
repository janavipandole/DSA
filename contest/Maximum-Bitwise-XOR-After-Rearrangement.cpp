#include <iostream>
using namespace std;
class Solution
{
public:
    string maximumXor(string s, string t)
    {
        int one = 0, zero = 0;
        for (auto ch : t)
        {
            if (ch == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        int i = 0;
        while (i < s.size() && one > 0 && zero > 0)
        {
            if (s[i] == '0')
            {
                t[i] = '1';
                one--;
            }
            else
            {
                t[i] = '0';
                zero--;
            }
            i++;
        }
        while (i < s.size() && zero > 0)
        {
            t[i] = '0';
            zero--;
            i++;
        }
        while (i < s.size() && one > 0)
        {
            t[i] = '1';
            one--;
            i++;
        }
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == t[i])
            {
                ans += '0';
            }
            else
            {
                ans += '1';
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "0110", t = "1110";
    cout << "Maximum Bitwise XOR After Rearrangement : " << s.maximumXor(str, t) << endl;
    return 0;
}