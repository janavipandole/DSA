#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> ans;
        unordered_map<string, int> hash;
        for (int i = 0; i < s1.size(); i++)
        {
            string word;
            while (i < s1.size() && s1[i] != ' ')
            {
                word += s1[i];
                i++;
            }
            hash[word]++;
        }
        for (int i = 0; i < s2.size(); i++)
        {
            string word;
            while (i < s2.size() && s2[i] != ' ')
            {
                word += s2[i];
                i++;
            }
            hash[word]++;
        }

        for (auto &[word, count] : hash)
        {
            if (count == 1)
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str1 = "this apple is sweet", str2 = "this apple is sour";
    cout << "Uncommon Words from Two Sentences : " << endl;
    vector<string> ans = s.uncommonFromSentences(str1, str2);
    for (auto word : ans)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}