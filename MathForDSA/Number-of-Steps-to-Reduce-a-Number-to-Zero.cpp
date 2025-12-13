#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int cnt = 0;
        while (num)
        {
            if (num % 2 == 0) num /= 2;
            else num -= 1;
            cnt++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    int n = 14;
    cout << "Number of Steps to Reduce a Number to Zero : " << s.numberOfSteps(n) << endl;
    return 0;
}