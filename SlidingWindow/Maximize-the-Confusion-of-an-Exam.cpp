#include <iostream>
using namespace std;

class Solution
{
public:
    // Brute force solution
    int maxConsecutiveAnswers_Brute(string s, int k)
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

    int maxConsecutiveAnswers(string s, int k)
    {
        int maxLen = 0, st = 0, end = 0, maxFreq = 0;
        int Tfeq = 0, Ffeq = 0;
        while (end < s.size())
        {
            if(s[end] == 'T') Tfeq++;
            else Ffeq++;
          maxFreq = max(maxFreq, max(Tfeq, Ffeq));
            while ((end - st + 1) - maxFreq > k)
            {
                if(s[st] == 'T') Tfeq--;
                else Ffeq--;
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
    string answerKey = "TTFF";
    int k = 2;
    cout << "Maximize the Confusion of an Exam : " << s.maxConsecutiveAnswers_Brute(answerKey, k) << endl;
    cout << "Maximize the Confusion of an Exam : " << s.maxConsecutiveAnswers(answerKey, k) << endl;

    return 0;
}