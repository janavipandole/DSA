#include <iostream>
using namespace std;
class Solution
{
public:
    // Brute force solution
    int lengthOfLongestSubstring_Brute(string s)
    {
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int hash[256] = {0};

            for (int j = i; j < s.size(); j++)
            {
                if (hash[s[j]] == 1)
                {
                    break;
                }

                maxLength = max(maxLength, j - i + 1);
                hash[s[j]] = 1;
            }
        }
        return maxLength;
    }

    // Optimal solution
    int lengthOfLongestSubstring_Optimal(string s)
    {
        unordered_map<char, int> charMap;
        int maxLen = 0;
        int st = 0;
        for (int end = 0; end < s.size(); end++)
        {
            if (charMap.find(s[end]) != charMap.end())
            {
                st = max(st, charMap[s[end]] + 1);
            }
            charMap[s[end]] = end;

            maxLen = max(maxLen, end - st + 1);
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << "Longest Substring Without Repeating Characters : " << s.lengthOfLongestSubstring_Brute(str) << endl;
    cout << "Longest Substring Without Repeating Characters : " << s.lengthOfLongestSubstring_Optimal(str) << endl;

    return 0;
}