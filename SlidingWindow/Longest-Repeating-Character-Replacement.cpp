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
            int cnt = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] != s[j]) cnt++;
                if (cnt > k) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
   
};
int main()
{
    Solution s;
    string str = "ABAA";
    int k = 0;
    cout << "Longest Repeating Character Replacement : " << s.characterReplacement_Brute(str, k) << endl;
    return 0;
}