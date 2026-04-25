#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        for (char &c : paragraph)
        {
            if (!isalpha(c))c = ' ';
            else c = tolower(c);
        }
        // Step 2: Extract words
        stringstream ss(paragraph);
        string word;

        while (ss >> word)
        {
            if (!bannedSet.count(word))
            {
                freq[word]++;
            }
        }

        // Step 3: Find max frequency word
        string answer;
        int maxFreq = 0;

        for (auto &p : freq)
        {
            if (p.second > maxFreq)
            {
                maxFreq = p.second;
                answer = p.first;
            }
        }

        return answer;
    }
};
int main()
{
    Solution s;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit";
    vector<string> banned = {"hit"};
    cout << "Most Common Word : " << s.mostCommonWord(paragraph, banned) << endl;
    return 0;
}