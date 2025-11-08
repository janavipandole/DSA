#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        vector<int> perm(n + 1, 0);
        int start = 0, end = n;

        for (int i = 0; i <= n; i++)
        {
            if (s[i] == 'I')
            {
                perm[i] = start;
                start++;
            }
            else
            {
                perm[i] = end;
                end--;
            }
        }
        return perm;
    }
};
int main()
{
    Solution s;
    string str = "IDID";
    cout << "DI String Match : " << endl;
    vector<int> ans = s.diStringMatch(str);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}