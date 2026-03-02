#include <iostream>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string trimTrailingVowels(string s)
    {
        string ans = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (isVowel(s[i]) == true)
            {
                s.pop_back();
            }
            else
            {
                break;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    string  str = "idea";
    cout << "Trim Trailing Vowels : "<<s.trimTrailingVowels(str) << endl;
    return 0;
}