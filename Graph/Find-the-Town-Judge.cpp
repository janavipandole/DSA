#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> Degree(n + 1, 0);

        for (auto edge : trust)
        {
            Degree[edge[0]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (Degree[i] == 0)
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
    vector<vector<int>> trust = {{1, 2}};
    int n = 2;
    cout << "Find the Town Judge : " << s.findJudge(n, trust) << endl;

    return 0;
}