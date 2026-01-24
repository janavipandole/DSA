#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        stringstream ss(text);
        string word;
        while (ss >> word)
        {
            bool ok = true;
            for (char c : word)
            {
                if (broken.count(c))
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string text = "hello world", brokenLetters = "ad";
    cout << "Maximum Number of Words You Can Type : " << s.canBeTypedWords(text, brokenLetters) << endl;
    return 0;
}