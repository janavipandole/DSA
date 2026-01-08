#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[i][0] == words[j][1] && words[i][1] == words[j][0])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"cd", "ac", "dc", "ca", "zz"};
    cout << "Find Maximum Number of String Pairs : " << s.maximumNumberOfStringPairs(words) << endl;
    return 0;
}