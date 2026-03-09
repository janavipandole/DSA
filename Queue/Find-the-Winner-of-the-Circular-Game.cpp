#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> solve;
        int start = 0;

        for (int i = 1; i <= n; i++)
        {
            solve.push_back(i);
        }
        while (solve.size() > 1)
        {
            start = (start - 1 + k) % solve.size();
            solve.erase(solve.begin() + start);
        }
        return solve[0];
    }
};
int main()
{
    Solution s;
    int n = 6, k = 5;
    cout << "Find the Winner of the Circular Game : " << s.findTheWinner(n, k) << endl;
    return 0;
}