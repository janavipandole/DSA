#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        vector<int> ans;
        long long mod = 1000000007LL;
        for (int i = 0; i < queries.size(); i++)
        {
            string num;
            long long sum = 0;
            for (int st = queries[i][0]; st <= queries[i][1]; st++)
            {
                sum += (s[st] - '0');
                if (s[st] != '0')
                    num += s[st];
            }
            if (num.size() <= 0)
                ans.push_back(0);
            else
                ans.push_back((stoll(num) * sum) % mod);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> queries = {{0, 9}};
    string str = "9876543210";

    cout << "Concatenate Non-Zero Digits and Multiply by Sum II : " << endl;

    vector<int> ans = s.sumAndMultiply(str, queries);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
