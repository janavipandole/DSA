#include <iostream>
using namespace std;
int reverseDigits(int n)
{
    int dummy = n;
    int indexPlace = 10;
    int reverseDigit = 0;
    while (dummy > 0)
    {
        int lastDigit = dummy % 10;
        reverseDigit = (reverseDigit * indexPlace) + lastDigit;
        dummy /= 10;
    }
    return reverseDigit;
}
int main()
{
    cout << "Reverse digits : " << reverseDigits(7789) << endl;
    return 0;
}