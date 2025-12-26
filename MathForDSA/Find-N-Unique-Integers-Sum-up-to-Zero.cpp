#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= n / 2; i++)
        {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 != 0)
        {
            ans.push_back(0);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n = 5;
    cout << "Find N Unique Integers Sum up to Zero : " << endl;
    vector<int> ans = s.sumZero(n);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}