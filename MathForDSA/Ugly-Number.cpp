#include <iostream>
using namespace std;
// Brute force solution
vector<int> primeFacOptimal(int n)
{
    vector<int> nums;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            nums.push_back(i);
            while (n % i == 0)n /= i;
        }
    }
    if (n != 1) nums.push_back(n);

    return nums;
}
bool isUglyBrute(int n)
{
    if (n <= 0) return false;
    vector<int> nums = primeFacOptimal(n);
    for (auto num : nums)
    {
        if (num >= 7) return false;
    }
    return true;
}
// Optimal solution
bool isUglyOptimal(int n)
{
    if (n <= 0) return false;
    if (n == 1) return true;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;

    return n == 1;
}
int main()
{
    int n = 14;
    cout << "Ugly Number Brute : " << isUglyBrute(n) << endl;
    cout << "Ugly Number Optimal : " << isUglyOptimal(n) << endl;
    return 0;
}