#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int countKeyChanges(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (tolower(s[i]) != tolower(s[i + 1]))
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    string str = "aAbBcC";
    cout << "Number of Changing Keys : " << s.countKeyChanges(str) << endl;
    return 0;
}