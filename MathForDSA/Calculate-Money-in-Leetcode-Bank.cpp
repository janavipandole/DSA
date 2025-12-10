#include <iostream>
using namespace std;
class Solution
{
public:
    int totalMoney(int n)
    {
        int totalCount = 0;
        int start = 1;
        int update = 2;

        for (int i = 1; i <= n; i++)
        {
            totalCount += start;
            start++;
            if (i % 7 == 0)
            {
                start = update;
                update++;
            }
        }
        return totalCount;
    }
};
int main()
{
    Solution s;

    cout << "Calculate Money in Leetcode Bank : " << s.totalMoney(10) << endl;
    return 0;
}