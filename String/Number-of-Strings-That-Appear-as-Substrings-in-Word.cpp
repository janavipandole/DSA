#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;

        for (auto &pat : patterns)
        {
            if (word.find(pat) != string::npos)
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
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";
    cout << "Number of Strings That Appear as Substrings in Word : " << s.numOfStrings(patterns, word) << endl;
    return 0;
}