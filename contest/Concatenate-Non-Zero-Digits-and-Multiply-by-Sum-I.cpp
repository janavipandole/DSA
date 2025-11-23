#include <iostream>
using namespace std;
class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        if(n == 0 || n == 1) return n;
        
        string digit;
        int sum = 0;
        while (n)
        {
            int num = n % 10;
            if (num != 0)
            {
                sum += num;
                digit += num + '0';
            }
            n /= 10;
        }
        reverse(digit.begin(), digit.end());
        return stoll(digit) * sum;
    }
};
int main()
{
    Solution s;
    long long num = 10203004;
    cout << "Concatenate Non-Zero Digits and Multiply by Sum I : " << s.sumAndMultiply(num) << endl;
    return 0;
}