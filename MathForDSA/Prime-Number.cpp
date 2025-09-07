#include <iostream>
using namespace std;
bool isPrime(int n)
{
    if (n == 1) return false;
    
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    cout << "Prime Number : " << isPrime(25)<<endl;
    return 0;
}