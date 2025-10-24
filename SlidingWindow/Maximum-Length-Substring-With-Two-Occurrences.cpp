#include <iostream>
using namespace std;
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            int hash[26] = {0};
            for(int j = i; j < s.size(); j++){
                hash[s[j] - 'a']++;
                if(hash[s[j] - 'a'] > 2) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
int main()
{
    Solution s;
    string str = "bcbbbcba";
    cout << "Maximum Length Substring With Two Occurrences : " << s.maximumLengthSubstring(str) << endl;
    return 0;
}