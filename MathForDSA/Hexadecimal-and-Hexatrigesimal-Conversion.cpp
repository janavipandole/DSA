#include <iostream>
using namespace std;

class Solution
{
public:
    string toBase(long long num, int base)
    {
        const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (num == 0)
            return "0";

        string result;
        while (num > 0)
        {
            result = digits[num % base] + result;
            num /= base;
        }
        return result;
    }
    string concatHex36(int n)
    {
        string hexadecimal = toBase(n * n, 16);
        string hexatrigesimal = toBase(n * n * n, 36);
        return hexadecimal + hexatrigesimal;
    }
};

int main()
{
    Solution s;
    int num = 13;
    cout << "Hexadecimal and Hexatrigesimal Conversion : " << s.concatHex36(num) << endl;
    return 0;
}