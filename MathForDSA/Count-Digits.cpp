#include <iostream>
using namespace std;
int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
int main()
{
    cout << "Count Digits : " << countDigits(7789) << endl;
    // Short cut to count digits
    cout << "Count Digits : " << ceil(log10(7789)) << endl;

    return 0;
}