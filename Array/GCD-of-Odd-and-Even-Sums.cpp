#include <iostream>
using namespace std;
class Solution
{
public:
    int gcdEA(int a, int b)
    {
        while (a > 0 && b > 0)
        {
            if (a > b)
                a %= b;
            else
                b %= a;
        }
        return a > 0 ? a : b;
    }
    int gcdOfOddEvenSums(int n)
    {
        int sumOdd = 0, sumEven = 0;
        int Even = 2, Odd = 1;

        while (n > 0)
        {
            sumEven += Even;
            sumOdd += Odd;
            Even += 2;
            Odd += 2;
            n--;
        }
        return gcdEA(sumOdd, sumEven);
    }
};
int main()
{
    Solution s;
    int n = 4;
    cout << "GCD of Odd and Even Sums : " << s.gcdOfOddEvenSums(n) << endl;
    return 0;
}