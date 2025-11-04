#include <iostream>
using namespace std;
class Solution
{
public:
    bool isValid(string s,int index, int cnt)
    {
        if (cnt < 0) return false;
        if (cnt > s.size() / 2) return false;
        if (index == s.size()) return cnt == 0;

        if(s[index] == '(') return isValid(s, index + 1, cnt + 1);

        if(s[index] == ')') return isValid(s, index + 1, cnt - 1);

        return  isValid(s, index + 1, cnt + 1) ||  isValid(s, index + 1, cnt - 1) || isValid(s, index + 1, cnt);

    }
    bool checkValidString(string s)
    {
        if (s[0] == ')')
        {
            return false;
        }

        return isValid(s, 0, 0);
    }
};
int main()
{
    Solution s;
    string str = "(*))";
    cout << "Valid Parenthesis String : " << s.checkValidString(str) << endl;
    return 0;
}