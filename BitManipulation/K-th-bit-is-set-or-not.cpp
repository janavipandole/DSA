#include <iostream>
using namespace std;

vector<int> decimaToBinary(int num)
{
    int n = num;
    vector<int> ans;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
bool checkKthBit(int n, int k)
{
    vector<int> binary = decimaToBinary(n);
    k = binary.size() - k - 1;

    if (binary[k] == 1 && k >= 0 && k < binary.size())
    {
        return true;
    }
    return false;
}

bool checkKthBitLS(int n, int k)
{
    if ((n & (1 << k) )== 1)
    {
        return true;
    }
    return false;
}
bool checkKthBitRS(int n, int k)
{
    if (((n >> k) & 1 )== 1)
    {
        return true;
    }
    return false;
}
int main()
{
    int n = 25528, k = 22;
    cout << "check Kt hBit : " << checkKthBitRS(n, k) << endl;
    return 0;
}