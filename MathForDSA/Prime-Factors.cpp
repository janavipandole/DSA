#include <iostream>
using namespace std;
// Brute force soliton
bool prime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
vector<int> primeFac(int n)
{
    vector<int> nums;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (prime(i))
                nums.push_back(i);
            if (n / i != i && prime(n / i))
                nums.push_back(n / i);
        }
    }
    return nums;
}

// Better solution
vector<int> primeFacBetter(int n)
{
    vector<int> nums;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            nums.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    return nums;
}
// Optimal solution
vector<int> primeFacOptimal(int n)
{
    vector<int> nums;
    for (int i = 2; i * i<= n; i++)
    {
        if (n % i == 0)
        {
            nums.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if(n != 1) nums.push_back(n);
    return nums;
}
int main()
{
    vector<int> ans = primeFacOptimal(60);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}