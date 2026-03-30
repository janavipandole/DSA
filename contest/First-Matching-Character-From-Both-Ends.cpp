#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstMatchingIndex(string s)
    {
        int i = 0;
        int n = s.size();

        while (i < n)
        {
            cout << s[i] << " " << s[n - i - 1] << endl;
            if (s[i] == s[n - i - 1])
            {
                return i;
            }
            i++;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    string str = "abcacbd";
    cout << "Find the Smallest Balanced Index : " << s.firstMatchingIndex(str) << endl;
    return 0;
}