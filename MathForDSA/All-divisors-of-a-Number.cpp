#include <iostream>
using namespace std;
// Brute foce solution
void print_divisorsBrute(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
// Optimal solution
void print_divisorsOptimal(int n)
{
    vector<int> nums;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            nums.push_back(i);
            if (i != n / i)
            {
                nums.push_back(n / i);
            }
        }
    }
    sort(nums.begin(), nums.end());
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    int n = 28;
    cout << "All divisors of a Number : " << endl;
    print_divisorsBrute(n);
    print_divisorsOptimal(n);
    return 0;
}