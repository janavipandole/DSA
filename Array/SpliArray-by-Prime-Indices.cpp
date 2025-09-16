#include <iostream>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
long long splitArray(vector<int> &nums)
{
    if (nums.size() == 0) return 0;

    long long sumA = 0, sumB = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(isPrime(i)) sumA += nums[i];
        else sumB += nums[i];
    }
    return abs(sumA - sumB);
}
int main()
{
    vector<int> nums = {-1, 5, 7, 0};
    cout << "Split Array by Prime Indices : " << splitArray(nums) << endl;
    return 0;
}