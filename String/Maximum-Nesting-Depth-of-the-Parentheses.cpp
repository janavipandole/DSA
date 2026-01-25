#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int leftPara = 0;
        int righPara = 0;
        int maxPara = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                leftPara++;
            }
            if (s[i] == ')')
            {
                righPara++;
            }

            maxPara = max(maxPara, leftPara - righPara);
        }
        return maxPara;
    }
};
int main()
{
    Solution s;
    string str = "(1+(2*3)+((8)/4))+1";
    cout << "Maximum Nesting Depth of the Parentheses : " << s.maxDepth(str) << endl;
    return 0;
}