#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        unordered_set<char> hash;
        for (auto ch : sentence)
        {
            hash.insert(ch);
        }

        return hash.size() == 26;
    }
};
int main()
{
    Solution s;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    cout << "Check if the Sentence Is Pangram : " << s.checkIfPangram(sentence) << endl;
    return 0;
}