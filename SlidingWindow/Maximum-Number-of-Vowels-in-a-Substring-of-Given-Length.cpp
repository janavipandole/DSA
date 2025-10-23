#include <iostream>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels_Brute(string s, int k)
    {
        int maxCnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int cntV = 0, cntK = 0;
            for (int j = i; j < s.size(); j++)
            {
                cntK++;
                if (cntK > k)
                    break;
                if (isVowel(s[j]))
                    cntV++;

                if (cntK == k)
                    maxCnt = max(maxCnt, cntV);
            }
        }
        return maxCnt;
    }

    int maxVowels_Better(string s, int k)
    {
        int maxCnt = 0, cntV = 0, cntK = 0, end = 0, st = 0;
        while (end < s.size())
        {
            cntK++;
            while (cntK > k){
                cntK--;
                if(isVowel(s[st])) cntV--;
                st++;
            }

            if (isVowel(s[end]))cntV++;

            if (cntK == k) maxCnt = max(maxCnt, cntV);
            end++;
        }
        return maxCnt;
    }

     int maxVowels_Optimal(string s, int k)
    {
        int maxCnt = 0, cntV = 0, cntK = 0, end = 0, st = 0;
        while (end < s.size())
        {
            cntK++;
            if (cntK > k){
                cntK--;
                if(isVowel(s[st])) cntV--;
                st++;
            }

            if (isVowel(s[end]))cntV++;

            if (cntK == k) maxCnt = max(maxCnt, cntV);
            end++;
        }
        return maxCnt;
    }
};
int main()
{
    Solution s;
    string str = "abciiidef";
    int k = 3;
    cout << "Maximum Number of Vowels in a Substring of Given Length : " << s.maxVowels_Brute(str, k) << endl;
    cout << "Maximum Number of Vowels in a Substring of Given Length : " << s.maxVowels_Better(str, k) << endl;
    cout << "Maximum Number of Vowels in a Substring of Given Length : " << s.maxVowels_Optimal(str, k) << endl;

    return 0;
}