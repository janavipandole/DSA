#include <iostream>
using namespace std;
void digit(int num)
{
    while (num > 0)
    {
        cout << num % 10 << " ";
        num /= 10;
    }
}
int main()
{
    digit(7789);
    return 0;
}