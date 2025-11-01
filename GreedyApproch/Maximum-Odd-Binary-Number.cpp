#include <iostream>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int cnt = 0;
        string ans(s.size(), '0');
        for (auto ch : s)
        {
            if (ch == '1')
            {
                cnt++;
            }
        }
        ans[s.size() - 1] = '1';
        int i = 0;
        while (cnt > 1)
        {
            ans[i] = '1';
            cnt--;
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "0011";
    cout << "Maximum Odd Binary Number : " << s.maximumOddBinaryNumber(str) << endl;
    return 0;
}