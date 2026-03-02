#include <iostream>
using namespace std;
class Solution
{
public:
    int minCost(int n)
    {
        int cost = 1;
        int a = 1;
        int b = n - 1;
        cost = a * b;
        while (b > 1)
        {
            b = b - 1;
            cost += a * b;
        }
        return cost;
    }
};
int main()
{
    Solution s;
    int n = 3;
    cout << "Minimum Cost to Split into Ones : " << s.minCost(n) << endl;
    return 0;
}