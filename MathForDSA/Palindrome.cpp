#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int k = x;
    int c = 0;
    while (k > 0)
    {
        if (c > INT_MAX / 10 || c < INT_MIN / 10)
        {
            return 0;
        }
        c = c * 10 + k % 10;
        k /= 10;
    }
    return c == x;
}

int main()
{
    cout << "Palindrome : " << isPalindrome(121) << endl;
    return 0;
}