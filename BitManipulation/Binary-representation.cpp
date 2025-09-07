#include <iostream>
using namespace std;
// Brute force soluiton
string decimaToBinary(int num)
{
    int n = num;
    string ans = "";

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string getBinaryRepBrute(int n)
{
    string ans = "00000000000000000000000000000000";
    string decimal = decimaToBinary(n);
    int i = ans.size() - 1, j = decimal.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (decimal[j] == '1')
        {
            ans[i] = '1';
        }
        i--;
        j--;
    }
    return ans;
}
// Optimal solution
string getBinaryRep(int n)
{
    string ans = "";
    for (int i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
    }

    return ans;
}
int main()
{
    int n = 2;
    cout << "Binary representation : " << getBinaryRep(n) << endl;
    return 0;
}