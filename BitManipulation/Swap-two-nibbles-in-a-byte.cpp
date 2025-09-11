#include <iostream>
using namespace std;
string decimalToBinary(int num)
{
    string ans = "00000000";
    int i = 7;
    while (num > 0)
    {
        if (num % 2 == 1)
        {
            ans[i] = '1';
        }
        num /= 2;
        i--;
    }
    return ans;
}
int binaryToDecima(string nums)
{
    int ans = 0;
    int n = nums.size() - 1;
    int pow = 1;
    for (int i = n; i >= 0; i--)
    {
        if (nums[i] == '1')
        {
            ans += pow;
        }
        pow *= 2;
    }
    return ans;
}
int swapNibbles(int n)
{
    string nums = decimalToBinary(n);
    string firstHalf, secondHalf;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < 4)
        {
            firstHalf += nums[i];
        }
        else
        {
            secondHalf += nums[i];
        }
    }
    string ans = secondHalf + firstHalf;

    return binaryToDecima(ans);
}
int main()
{
    // 0100 0110
    cout << "Swap two nibbles in a byte : " << swapNibbles(100) << endl;
    return 0;
}
