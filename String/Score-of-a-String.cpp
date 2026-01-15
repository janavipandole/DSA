#include <iostream>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int count = 0;
        for (int i = 1; i < s.size(); i++)
        {
            count += abs(s[i] - s[i - 1]);
        }
        return count;
    }
};
int main()
{
    Solution s;
    string str = "hello";
    cout << "Score of a String : " << s.scoreOfString(str) << endl;
    return 0;
}