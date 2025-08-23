#include <iostream>
using namespace std;

void printName(string name, int count)
{
    if (count == 4)
        return;

    cout << "Name : " << name << endl;
    count++;
    printName(name, count);
}

void print1toN(int i, int n)
{
    if (i > n)
        return;

    cout << i << " ";
    i++;
    print1toN(i, n);
}

void printNto1(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    n--;
    printNto1(n);
}

void print1toNBacktraking(int n)
{
    if (n <= 0)
        return;

    print1toNBacktraking(n - 1);
    cout << n << " ";
}

void printNto1Backtraking(int n)
{
    if (n <= 0)
        return;

    cout << n << " ";
    printNto1Backtraking(n - 1);
}

void sumOfNParameters(int n, int sum)
{
    if (n <= 0)
    {
        cout << "Sum : " << sum;
        return;
    }

    sumOfNParameters(n - 1, sum + n);
}

int sumOfN(int n)
{
    if (n <= 0)
        return 0;

    return n + sumOfN(n - 1);
}

int factorialOfN(int n)
{
    if (n == 1)
        return 1;

    return n * factorialOfN(n - 1);
}

void reverseA1(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    swap(nums[left], nums[right]);
    reverseA1(nums, left + 1, right - 1);
}
void reverseA2(vector<int> &nums, int i)
{
    int n = nums.size();
    if (i >= n / 2)
    {
        return;
    }
    swap(nums[i], nums[n - i - 1]);
    reverseA2(nums, i + 1);
}
void revrseArray(vector<int> &nums)
{
    reverseA1(nums, 0, nums.size() - 1);
    reverseA2(nums, 0);
    return;
}

bool isPalindreonStr(string s, int i)
{
    int n = s.size();

    if (i >= n - i - 1)
        return true;

    if (s[i] != s[n - i - 1])
        return false;
    return isPalindreonStr(s, i + 1);
}
bool isPalindrom(string s)
{
    return isPalindreonStr(s, 0);
}
int nthFibonachi(int n)
{
    if (n == 0 || n == 1)
        return n;

    return nthFibonachi(n - 1) + nthFibonachi(n - 2);
}

int main()
{
    // printName("Janavi", 0);
    // cout << endl;
    // print1toN(1, 10);
    // cout << endl;
    // printNto1(10);
    // cout << endl;
    // print1toNBacktraking(5);
    // cout << endl;
    // printNto1Backtraking(10);
    // cout << endl;
    // sumOfNParameters(5, 0);
    // cout << endl;
    // cout << sumOfN(5) << endl;
    // cout << factorialOfN(6) << endl;
    // vector<int> nums = {1, 2, 3, 4, 5, 6};
    // revrseArray(nums);
    // for (auto num : nums)
    //     cout << num << " ";
    // cout << endl;
    // cout<<isPalindrom("janavi")<<endl;
    // cout<<nthFibonachi(2)<<endl;
    return 0;
}
