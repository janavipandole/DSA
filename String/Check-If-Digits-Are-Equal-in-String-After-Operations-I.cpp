#include <iostream>
using namespace std;
bool hasSameDigits(string s)
{
    while (s.size() > 2)
    {
        string newS = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            int digit = (s[i] - '0' + s[i + 1] - '0') % 10;
            newS += (digit + '0');
        }
        s = newS;
    }
    if (s[0] == s[1]) return true;

    return false;
}
int main()
{
    string s = "3902";
    cout << "Check If Digits Are Equal in String After Operations I : " << hasSameDigits(s) << endl;
    return 0;
}