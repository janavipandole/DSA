#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrom(string s)
    {
        int start = 0, end = s.size()-1;
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            string word = "";
            for (int j = i; j < s.size(); j++)
            {
                word += s[j];
                if (isPalindrom(word) && ans.size() <= word.size())
                {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "babad";
    cout << "Longest Palindromic Substring : " << s.longestPalindrome(str) << endl;
    return 0;
}