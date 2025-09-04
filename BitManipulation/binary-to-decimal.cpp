#include <iostream>
using namespace std;
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
int main()
{
    string nums = "1011";
    cout << "binary To Decima: " << binaryToDecima(nums) << endl;
    return 0;
}