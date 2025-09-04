#include <iostream>
using namespace std;
int xorOperation(int n, int start)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= start + i * 2;
    }
    return ans;
}
int main()
{
    int n = 5, start = 0;
    cout << "XOR Operation in an Array : " << xorOperation(n, start) << endl;
    return 0;
}