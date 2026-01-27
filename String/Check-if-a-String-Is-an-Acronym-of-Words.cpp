#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        string word;
        for (int i = 0; i < words.size(); i++)
        {
            word += words[i][0];
        }
        return word == s;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"alice", "bob", "charlie"};
    string str = "abc";
    cout << "Check if a String Is an Acronym of Words : " << s.isAcronym(words,str) << endl;
    return 0;
}
