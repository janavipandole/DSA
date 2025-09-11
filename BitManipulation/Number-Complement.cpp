#include <iostream>
using namespace std;
// Brute force solution
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
string decimaToBinary(int num)
{
    int n = num;
    string ans = "";

    while (n > 0)
    {
        if (n % 2 == 1)
            ans += '1';
        else
            ans += '0';
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int findComplementBrute(int num)
{
    string bits = decimaToBinary(num);
    string ans;
    for (int i = 0; i < bits.size(); i++)
    {
        if (bits[i] == '1')
        {
            ans += '0';
        }
        else
        {
            ans += '1';
        }
    }

    return binaryToDecima(ans);
}
// Optimal solution
int findComplementOptimal(int num)
{
    int ans = 0;
    int pow = 1;
    while(num > 0){
        if(num % 2 == 0){
            ans += pow;
        }
        pow *= 2;
        num /= 2;
    }
    return ans;
}
int main()
{
    cout << "Number Complement : " << findComplementBrute(5) << endl;
    cout << "Number Complement : " << findComplementOptimal(5) << endl;
    return 0;
}