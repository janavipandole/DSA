#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> count;
        for (auto c : s)
        {
            count[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (count[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }

    int firstUniqChar(string s)
    {
        unordered_map<char, int> count;
        queue<int> Qu;

        for (int i = 0; i < s.size(); i++)
        {
            if (count.find(s[i]) == count.end())
            {
                Qu.push(i);
            }

            count[s[i]]++;
        }
        while (!Qu.empty() && count[s[Qu.front()]] != 1)
        {
            Qu.pop();
        }

        return Qu.empty() ? -1 : Qu.front();
    }
    int firstUniqChar(string s)
    {
        vector<int> count(26, 0);

        for (char c : s)
        {
            count[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
int main()
{
    Solution s;
    string str = "loveleetcode";
    cout << "First Unique Character in a String : " << s.firstUniqChar(str) << endl;
    return 0;
}
