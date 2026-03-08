#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> count;
        for (auto c : s)
        {
            count[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (count[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}