#include <iostream>
using namespace std;
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            bool isMatch = true;
            for (int j = 0; j < pref.size(); j++)
            {
                if (words[i][j] != pref[j])
                {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"pay", "attention", "practice", "attend"};
    string pref = "at";
    cout << "Counting Words With a Given Prefix : " << s.prefixCount(words, pref) << endl;

    return 0;
}