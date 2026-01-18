#include <iostream>
using namespace std;

class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool isInteger(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    bool isSpace(char ch)
    {
        return ch == ' ';
    }

    int vowelConsonantScore(string s)
    {
        int c = 0, v = 0;
        for (auto ch : s)
        {
            if(isVowel(ch)) v++;
            else if(isInteger(ch)) continue;
            else if(isSpace(ch)) continue;
            else c++;
        }
        
        if(c > 0) return floor(v / c);
        return 0;
    }
};

int main()
{
    Solution s;
    string str = "o0";
    cout << "Vowel-Consonant Score : " << s.vowelConsonantScore(str) << endl;
    return 0;
}