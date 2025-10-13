#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        vector<int> ans(code.size(), 0);
        if (k == 0) return ans;
        int n = code.size();

        if (k > 0)
        {
            for (int i = 0; i < n; i++)
            {
                int cnt = 1;
                int index = i;
                while (cnt <= k)
                {
                    index += 1;
                    ans[i] += code[index % n];
                    cnt++;
                }
            }
        }else{
             for (int i = 0; i < n; i++)
            {
                int cnt = 1;
                int index = 0;
                while (cnt <= abs(k))
                {
                    index = n - cnt + i;
                    ans[i] += code[index % n];
                    cnt++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> code = {2,4,9,3};
    int k = -2;
    cout<<"Defuse the Bomb : ";
    vector<int> ans = s.decrypt(code, k);
    for (auto num : ans)
    {
        cout << num << endl;
    }
    return 0;
}