#include <iostream>
using namespace std;

class Solution
{
public:
    int partitionString_Brute(string s)
    {
        int cnt = 0;
        int i = 0;
        while (i < s.size())
        {
            vector<int> freq(26, 0);
            bool duplicateFound = false;
            for (int j = i; j < s.size(); j++)
            {
                if (freq[s[j] - 'a'] != 0)
                {
                    i = j;
                    cnt++;
                    duplicateFound = true;
                    break;
                }
                freq[s[j] - 'a']++;
            }
            if (!duplicateFound)
            {
                cnt++; // last partition
                break;
            }
        }
        return cnt;
    }
    int partitionString_Optimal(string s)
    {
        vector<int> hash(26, 0);
        int cnt = 1;
        for (char c : s)
        {
            if (hash[c - 'a'] != 0)
            {
                cnt++;
                for (int i = 0; i < 26; i++)
                {
                    hash[i] = 0;
                }
            }
            hash[c - 'a'] = 1;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    string str = "abacaba";
    cout << "Optimal Partition of String : " << s.partitionString_Brute(str) << endl;
    cout << "Optimal Partition of String : " << s.partitionString_Optimal(str) << endl;

    return 0;
}