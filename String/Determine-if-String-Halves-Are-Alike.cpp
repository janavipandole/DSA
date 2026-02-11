#include <iostream>
using namespace std;

class Solution
{
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool halvesAreAlike(string s)
    {
        int firstHalf = 0, secondHalf = 0;
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(isVowel(s[i])) firstHalf++;
            if(isVowel(s[j])) secondHalf++;
            i++;
            j--;
        }
        return secondHalf == firstHalf;
    }
};

int main()
{
    Solution s;
    string strs = "book";
    cout << "Determine if String Halves Are Alike : " << s.halvesAreAlike(strs) << endl;
    return 0;
}