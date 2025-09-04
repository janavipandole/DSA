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

int setKthBitBrute(int n, int k)
{
    vector<int> ans = decimaToBinary(n);
    k = ans.size() - k - 1;
    if (k >= 0 && k < ans.size() && ans[k] == 0)
    {
        ans[k] = 1;
    }
    return binaryToDecima(ans);
}
int setKthBit(int n, int k)
{
    return (n | (1 << k));
}
int main()
{
    int n = 10, k = 2;
    cout << "set Kth Bit : " << setKthBitBrute(n, k) << endl;
    cout << "set Kth Bit : " << setKthBit(n, k) << endl;

    return 0;
}