#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int longestKSubstr_Brute(string &s, int k)
    {
        int maxLen = -1;

        for (int i = 0; i < s.size(); i++)
        {
            set<char> ch;
            for (int j = i; j < s.size(); j++)
            {
                if (ch.size() > k) break;
                ch.insert(s[j]);
                if (ch.size() == k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    int longestKSubstr_Better(string &s, int k)
    {
        int maxLen = -1, st = 0, end = 0, n = s.size();
        unordered_map<char, int> mpp;

        while (end < n)
        {
            mpp[s[end]]++;
            while (mpp.size() > k)
            {
                mpp[s[st]]--;
                if (mpp[s[st]] == 0)
                    mpp.erase(s[st]);
                st++;
            }
            if (mpp.size() == k)
                maxLen = max(maxLen, end - st + 1);
            end++;
        }
        return maxLen;
    }

    int longestKSubstr_Optimal(string &s, int k)
    {
        int maxLen = -1, st = 0, end = 0, n = s.size();
        unordered_map<char, int> mpp;

        while (end < n)
        {
            mpp[s[end]]++;
            if (mpp.size() > k)
            {
                mpp[s[st]]--;
                if (mpp[s[st]] == 0) mpp.erase(s[st]);
                st++;
            }
            if (mpp.size() == k) maxLen = max(maxLen, end - st + 1);
            end++;
        }
        return maxLen;
    }
};
int main()
{
    Solution s;

    string str = "tvtgv";
    int k = 4;
    cout << "Longest Substring with K Uniques : " << s.longestKSubstr_Brute(str, k) << endl;
    cout << "Longest Substring with K Uniques : " << s.longestKSubstr_Better(str, k) << endl;
    cout << "Longest Substring with K Uniques : " << s.longestKSubstr_Optimal(str, k) << endl;

    return 0;
}