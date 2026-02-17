#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        unordered_map<char, int> firstIndex;
        int maxLen = -1;

        for (int i = 0; i < s.size(); i++)
        {
            // If character seen first time
            if (firstIndex.find(s[i]) == firstIndex.end())
            {
                firstIndex[s[i]] = i;
            }
            else
            {
                int length = i - firstIndex[s[i]] - 1;
                maxLen = max(maxLen, length);
            }
        }

        return maxLen;
    }
};
int main()
{
    Solution s;
    string str = "abca";
    cout << "Largest Substring Between Two Equal Characters : " << s.maxLengthBetweenEqualCharacters(str) << endl;
    return 0;
}