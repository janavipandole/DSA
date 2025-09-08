#include <iostream>
using namespace std;
int countPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            count++;

            for (int j = i * 2; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return count;
}
int main()
{
    cout<<"Count primes : "<<countPrimes(10)<<endl;
    return 0;
}