#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        map<string, int> hash1, hash2;
        int count = 0;
        for (auto word : words1)
        {
            hash1[word]++;
        }

        for (auto word : words2)
        {
            hash2[word]++;
        }
        for (auto &p : hash1)
        {
            string word = p.first;

            if (hash1[word] == 1 && hash2[word] == 1)
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
    vector<string> words1 = {"leetcode", "is", "amazing", "as", "is"}, words2 = {"amazing", "leetcode", "is"};
    cout << "Count Common Words With One Occurrence : " << s.countWords(words1, words2) << endl;
    return 0;
}