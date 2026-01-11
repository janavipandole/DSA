#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int residuePrefixes(string s)
    {
        int count = 0;
        int distinct = 0;
        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';

            if (freq[idx] == 0)
            {
                distinct++;
            }
            freq[idx]++;

            if (distinct == (i + 1) % 3)
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
    string str = "ook";
    cout << "Count Residue Prefixes : " << s.residuePrefixes(str) << endl;
    return 0;
}