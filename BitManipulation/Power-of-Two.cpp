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
bool isPowerOfTwoBrute(int n)
{
    vector<int> nums = decimaToBinary(n);
    int cnt = 0;
    for(auto num : nums){
        if(num == 1) cnt++;
        if(cnt > 1) return false;
    }
    return true;
}
// Optimal solution
bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}
int main()
{
    int n = 211;
    cout << "Power Of Two Brute solution : " << isPowerOfTwoBrute(n) << endl;
    cout << "Power Of Two : " << isPowerOfTwo(n) << endl;

    return 0;
}