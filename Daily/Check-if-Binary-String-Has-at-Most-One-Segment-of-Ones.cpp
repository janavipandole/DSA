#include <iostream>
using namespace std;
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        bool zeroFound = false;
        for (auto ch : s)
        {
            if (ch == '0')
            {
                zeroFound = true;
            }
            else if(ch == '1' && zeroFound)
            {
                return false;
            }

           
        }
        return true;
    }
};
int main()
{
    Solution s;
    string str = "110";
    cout << "Check if Binary String Has at Most One Segment of Ones : "<<s.checkOnesSegment(str) << endl;
    return 0;
}