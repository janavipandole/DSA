#include <iostream>
using namespace std;

class Solution
{
public:
    int sumBase(int n, int k)
    {
        int sum = 0;

        while (n > 0)
        {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    int n = 34, k = 6;
    cout << "Sum of Digits in Base K : " << s.sumBase(n, k) << endl;
    return 0;
}