#include <iostream>
using namespace std;
// Brute force solution
int findXORBrute(int left, int right)
{
    int ans = 0;
    for (int i = left; i <= right; i++)
        ans ^= i;

    return ans;
}
// Optimal solution
int XOR(int n)
{
    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    else
        return n;
}
int findXOROptimal(int left, int right)
{
    return XOR(left - 1) ^ XOR(right);
}
int main()
{
    int left = 4, right = 8;
    cout << "Find XOR of numbers from L to R : " << findXORBrute(left, right) << endl;
    cout << "Find XOR of numbers from L to R : " << findXOROptimal(left, right) << endl;
    return 0;
}