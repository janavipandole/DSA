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
        vector<int> hash(256, -1);
        int maxLen = 0;
        int st = 0, end = 0, n = s.size();
        while (end < n){
            if(hash[s[end]] != -1){
                if(hash[s[end]] >= st) st = hash[s[end]] + 1;
            }
            maxLen = max(maxLen, end - st + 1);
            hash[s[end]] = end;
            end++;
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    string str = "au";
    cout << "Longest Substring Without Repeating Characters : " << s.lengthOfLongestSubstring_Brute(str) << endl;
    cout << "Longest Substring Without Repeating Characters : " << s.lengthOfLongestSubstring_Optimal(str) << endl;

    return 0;
}