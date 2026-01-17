#include <iostream>
using namespace std;
class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int maxWords = 0;

        for (const string &s : sentences)
        {
            int words = 1; // at least one word per sentence
            for (char c : s)
            {
                if (c == ' ')
                {
                    words++;
                }
            }
            maxWords = max(maxWords, words);
        }

        return maxWords;
    }
};
int main()
{
    Solution s;
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout << "Maximum Number of Words Found in Sentences : " << s.mostWordsFound(sentences) << endl;
    return 0;
}