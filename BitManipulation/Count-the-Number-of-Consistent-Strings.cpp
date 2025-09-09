#include <iostream>
#include <unordered_set>
using namespace std;
int countConsistentStrings(string allowed, vector<string> &words)
{
    int cnt = 0;
    unordered_set<char> aset(allowed.begin(), allowed.end());

    for (int i = 0; i < words.size(); i++)
    {
        bool wordFound = true;
        for (int j = 0; j < words[i].size(); j++)
        {

            if (aset.find(words[i][j]) == aset.end())
            {
                wordFound = false;
                break;
            }
        }
        if (wordFound)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    string allowed = "ab";
    vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
    cout << "Count the Number of Consistent Strings : " << countConsistentStrings(allowed, words) << endl;
    return 0;
}