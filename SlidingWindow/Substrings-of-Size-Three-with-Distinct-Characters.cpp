#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    int countGoodSubstrings_Brute(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            set<char> ch;
            for (int j = i; j < s.size(); j++)
            {

                if (ch.find(s[j]) != ch.end() || ch.size() > 3) break;
                ch.insert(s[j]);
                if (ch.size() == 3)count++;
            }
        }
        return count;
    }

    int countGoodSubstrings_Optimal(string s)
    {
        int count = 0;
        if (s.size() < 3) return 0;
        for (int i = 0; i <= s.size() - 3; ++i) {
            string sub = s.substr(i, 3);
            set<char> charSet;

            for (char c : sub) charSet.insert(c);
            if (charSet.size() == 3) count++;
        }

        return count;
    }
};
int main()
{
    Solution s;
    string str = "xyzzaz";
    cout << "Substrings of Size Three with Distinct Characters : " << s.countGoodSubstrings_Brute(str) << endl;
    cout << "Substrings of Size Three with Distinct Characters : " << s.countGoodSubstrings_Optimal(str) << endl;

    return 0;
}