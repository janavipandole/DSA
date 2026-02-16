#include <iostream>
using namespace std;
class Solution
{
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int count = 0;

        for (auto &w : words)
        {
            // check if s starts with w
            if (s.find(w) == 0)
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
    vector<string> words = {"feh", "w", "w", "lwd", "c", "s", "vk", "zwlv", "n", "w", "sw", "qrd", "w", "w", "mqe", "w", "w", "w", "gb", "w", "qy", "xs", "br", "w", "rypg", "wh", "g", "w", "w", "fh", "w", "w", "sccy"};
    string str = "w";
    cout << "Count Prefixes of a Given String : " << s.countPrefixes(words, str) << endl;

    return 0;
}