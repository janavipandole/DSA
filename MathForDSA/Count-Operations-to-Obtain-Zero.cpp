#include <iostream>
using namespace std;
class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int cnt = 0;

        while (num1 > 0 && num2 > 0)
        {
            if (num1 >= num2)
            {
                num1 -= num2;
            }
            else
            {
                num2 -= num1;
            }
            cnt++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    int num1 = 2, num2 = 3;
    cout << "Count Operations to Obtain Zero : " << s.countOperations(num1, num2) << endl;
    return 0;
}