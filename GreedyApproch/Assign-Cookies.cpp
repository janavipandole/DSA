#include <iostream>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int r = 0, l = 0, n = g.size(), m = s.size();

        while(r < n && l < m){
            if(g[r] <= s[l]) r++;
            l++;
        }
        return r;
    }
};
int main()
{
    Solution s;
    vector<int> Greed = {1, 2, 3}, cookie = {1, 1};
    cout << "Assign Cookies : " << s.findContentChildren(Greed, cookie) << endl;
    return 0;
}