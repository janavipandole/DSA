#include <iostream>
using namespace std;
class Solution
{
public:
    string mergeCharacters(string s, int k)
    {
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j] && j - i <= k)
                {
                    s.erase(s.begin() + j);
                    j--;
                }
            }
        }
        return s;
    }
};
int main()
{
    Solution s;
    string str = "hhh";
    int k = 1;
    cout << "Merge Close Characters : " << s.mergeCharacters(str, k) << endl;
    return 0;
}