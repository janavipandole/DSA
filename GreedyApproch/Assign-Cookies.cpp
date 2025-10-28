#include <iostream>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
       sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int i = 0, j = 0;
        int n = g.size();
        int m = s.size();
        while(i < n && j < m){
            if(g[i] > s[j]){
                j++;
            }
           else
            {
                cnt++;
                i++;
                j++;
            }   
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> Greed = {1, 2, 3}, cookie = {1, 1};
    cout << "Assign Cookies : " << s.findContentChildren(Greed, cookie) << endl;
    return 0;
}