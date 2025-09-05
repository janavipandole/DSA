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
int removeLastSetBitBrute(int n)
{
    vector<int> ans = decimaToBinary(n);
    int len = ans.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (ans[i] == 1)
        {
            ans[i] = 0;
            break;
        }
    }
    return binaryToDecima(ans);
}
// Optimal solution
int removeLastSetBitOptimal(int n)
{
    return (n & n - 1);
}
int main()
{
    cout << "Remove the last set bit : " << removeLastSetBitBrute(12) << endl;
    cout << "Remove the last set bit : " << removeLastSetBitOptimal(12) << endl;

    return 0;
}