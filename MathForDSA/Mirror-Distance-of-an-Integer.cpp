#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int mirrorDistance(int n)
    {
        int dummy = n;
        int numNum = 0;
        while (dummy)
        {
            numNum = ((numNum * 10) + (dummy % 10));
            dummy /= 10;
        }

        return abs(n - numNum);
    }
};
int main()
{
    Solution s;
    int n = 25;
    cout << "Mirror Distance of an Integer : " << s.mirrorDistance(n) << endl;
    return 0;
}