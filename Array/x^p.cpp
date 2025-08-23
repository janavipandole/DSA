#include <iostream>
using namespace std;

int main()
{
    int x = 3;
    int n = 9;
    int val1 = n;
    int val2 = x;
    int ans = 1;
    while (n > 0)
    {
        int val = n % 2 == 1;
        if (val)
        {
            ans *= x;
        }
        x *= x;
        n = n / 2;
        // cout<<n<<" ";
    }
    cout << "answer" << endl;
    cout << val2 << "^" << val1 << ":" << ans << endl;
    return 0;
}