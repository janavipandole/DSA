#include <iostream>
using namespace std;
class Solution
{
public:
    string largestEven(string s)
    {
        if (s[s.size() - 1] == '2')
        {
            return s;
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '2')
            {
                return s.substr(0, i+1);
            }
        }
        return "";
    }
};
int main()
{
    Solution s;
    string str = "22121";
    cout << "Largest Even Number : " << s.largestEven(str) << endl;
    return 0;
}