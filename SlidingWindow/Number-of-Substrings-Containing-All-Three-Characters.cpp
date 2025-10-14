#include <iostream>
using namespace std;
class Solution
{
public:
    int numberOfSubstrings_Brute(string &s)
    {
        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int hash[3] = {-1, -1, -1};
            for (int j = i; j < s.size(); j++)
            {
                hash[s[j] - 'a']++;
                if (hash[0] != -1 && hash[1] != -1 && hash[2] != -1)
                {
                    cnt += s.size() - j;
                    break;
                }
            }
        }
        return cnt;
    }
    int numberOfSubstrings_Optimal(string &s)
    {
        vector<int> lastseen = {-1, -1, -1};
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            lastseen[s[i] - 'a'] = i;
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) count = count + min({lastseen[0], lastseen[1], lastseen[2]}) + 1;
        }
        return count;
    }
};
int main()
{
    Solution s;
    string str = "abcabc";
    cout << "Number of Substrings Containing All Three Characters : " << s.numberOfSubstrings_Brute(str) << endl;
    cout << "Number of Substrings Containing All Three Characters : " << s.numberOfSubstrings_Optimal(str) << endl;

    return 0;
}