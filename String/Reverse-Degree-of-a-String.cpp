#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int reverseDegree(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += ('z' - s[i] + 1) * (i + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "abc";
    cout << "Reverse Degree of a String : " << s.reverseDegree(str) << endl;
    return 0;
}