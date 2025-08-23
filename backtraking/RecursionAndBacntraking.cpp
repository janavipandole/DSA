#include <iostream>
using namespace std;

// Recursion
void funR(int i, int n)
{
    if (i > n)
        return;

    cout << i << " ";
    funR(i + 1, n);
}

// Backtraking
void funB(int n)
{
    if (n < 0)
        return;

    funB(n - 1);
    cout << n << " ";
}
int main()
{
    // recursion
    funR(0, 5);
    cout << endl;
    // backtraing
    funB(5);
    return 0;
}