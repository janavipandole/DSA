#include <iostream>
using namespace std;
// Brute force solution
int xorOperationOfNBrute(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans ^= i;
    }
    return ans;
}
// Optimal solution
int xorOperationOfNOptimal(int n)
{
    if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else if (n % 4 == 3 ) return 0;
    else return n;
}
int main()
{
    int n = 4;
    cout << "XOR of Numbers in a Given Range : " << xorOperationOfNBrute(n) << endl;
    cout << "XOR of Numbers in a Given Range : " << xorOperationOfNOptimal(10) << endl;

    return 0;
}