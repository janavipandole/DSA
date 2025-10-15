#include <iostream>
using namespace std;

class Solution
{
public:
    // Brute force solution
    int characterReplacement_Brute(string s, int k)
    {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> mpp(26, 0);
            int maxFreq = 0, change = 0;
            for (int j = i; j < s.size(); j++)
            {
                maxFreq = max(maxFreq, ++mpp[s[j] - 'A']);
                change = (j - i + 1) - maxFreq;
                if (change <= k) maxLen = max(maxLen, j - i + 1);
                else break;
            }
        }
        return maxLen;
    }
    int characterReplacement_Better(string s, int k)
    {
        int maxLen = 0, st = 0, end = 0, maxFreq = 0;
        vector<int> mpp(26, 0);
        while (end < s.size())
        {
            maxFreq = max(maxFreq, ++mpp[s[end] - 'A']);
            while ((end - st + 1) - maxFreq > k)
            {
                mpp[s[st] - 'A']--;
                st++;
            }
            maxLen = max(maxLen, end - st + 1);
            end++;
        }
        return maxLen;
    }
    // Optimal solution
    int characterReplacement_Optimal(string s, int k)
    {
        int maxLen = 0, st = 0, end = 0, maxFreq = 0;
        vector<int> mpp(26, 0);
        while (end < s.size())
        {
            maxFreq = max(maxFreq, ++mpp[s[end] - 'A']);
            if ((end - st + 1) - maxFreq > k)
            {
                mpp[s[st] - 'A']--;
                st++;
            }
            maxLen = max(maxLen, end - st + 1);
            end++;
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    string str = "AABABBA";
    int k = 1;
    cout << "Longest Repeating Character Replacement : " << s.characterReplacement_Brute(str, k) << endl;
    cout << "Longest Repeating Character Replacement : " << s.characterReplacement_Better(str, k) << endl;
    cout << "Longest Repeating Character Replacement : " << s.characterReplacement_Optimal(str, k) << endl;

    return 0;
}