#include <iostream>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n)
    {
        int i = 1;
        while (i > 0)
        {
            int num = pow(2, i);
            if (num - 1 >= n)
            {
                return num - 1;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }
};
int main()
{
    Solution s;
    int  n = 5;
    cout << "Smallest Number With All Set Bits : " << s.smallestNumber(n) << endl;
    return 0;
}