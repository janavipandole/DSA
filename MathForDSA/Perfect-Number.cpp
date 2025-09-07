#include <iostream>
using namespace std;
int print_divisors_sum(int n)
{
    int sum = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i && i != 1)
            {
                sum += (n / i);
            }
        }
    }
    return sum;
}
bool checkPerfectNumber(int num)
{
    return print_divisors_sum(num) == num;
}
int main()
{
    int n = 28;
    cout << "All divisors of a Number : " << checkPerfectNumber(n) << endl;
    return 0;
}