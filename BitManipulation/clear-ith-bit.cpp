#include <iostream>
using namespace std;
// Brute force solution
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

int binaryToDecima(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size() - 1;
    int pow = 1;
    for (int i = n; i >= 0; i--)
    {
        if (nums[i] == 1)
        {
            ans += pow;
        }
        pow *= 2;
    }
    return ans;
}

int clearBitBrute(int n, int k)
{
    vector<int> ans = decimaToBinary(n);
    k = k - 1;
    if (k >= 0 && k < ans.size() && ans[k] == 1)
    {
        ans[k] = 0;
    }
    return binaryToDecima(ans);
}

// Optimal solution
int clearBit(int n, int k)
{
 return (n & (~ (1 << k)));  
}
int main()
{
    int n = 13 , k = 2;
    cout << "replace Bit : " << clearBitBrute(n, k) << endl;
    cout << "replace Bit : " << clearBit(n, k) << endl;
    return 0;
}