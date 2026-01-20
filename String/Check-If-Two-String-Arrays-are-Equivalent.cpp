#include <iostream>
using namespace std;
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string w1;
        string w2;

        for (auto word : word1)
        {
            w1 += word;
        }

        for (auto word : word2)
        {
            w2 += word;
        }
        return w1 == w2;
    }
};
int main()
{
    Solution s;
    vector<string> word1 = {"ab", "c"}, word2 = {"a", "bc"};
    cout << "Check If Two String Arrays are Equivalent : " << s.arrayStringsAreEqual(word1, word2) << endl;
    return 0;
}