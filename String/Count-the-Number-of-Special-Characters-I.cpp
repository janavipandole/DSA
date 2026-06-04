#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int count = 0;
        unordered_map<char, int> hash;

        for (int i = 0; i < word.size(); i++)
        {
            hash[word[i]]++;
        }

        for (auto &[ch, cnt] : hash)
        {
            if (hash.find(tolower(ch)) != hash.end() && hash.find(toupper(ch)) != hash.end())
            {
                count++;
            }
        }
        return count / 2;
    }
};

int main()
{
    Solution s;
    string word = "aaAbcBC";
    cout << "Count the Number of Special Characters I : " << s.numberOfSpecialChars(word) << endl;
    return 0;
}