#include <iostream>
using namespace std;
// Brute force solution
bool canAliceWinBrute(vector<int> &nums)
{
    int singleDigitSum = 0;
    int doubleDigitSum = 0;

    for (auto num : nums)
    {
        int digit = 0;
        int dummy = num;
        while (dummy > 0)
        {
            digit++;
            dummy /= 10;
        }
        if (digit == 1)
            singleDigitSum += num;
        else
            doubleDigitSum += num;
    }
    if (doubleDigitSum == singleDigitSum)
    {
        return false;
    }
    return true;
}
// Optimal solution
bool canAliceWinOptimal(vector<int> &nums)
{
    int singleDigitSum = 0;
    int doubleDigitSum = 0;

    for (auto num : nums)
    {
        if (num < 10)
        {
            singleDigitSum += num;
        }
        else
        {
            doubleDigitSum += num;
        }
    }
    return doubleDigitSum == singleDigitSum ? false : true;
}
int main()
{
    vector<int> nums = {5, 5, 5, 5};
    cout << "Find if Digit Game Can Be Won : " << canAliceWinBrute(nums) << endl;
    cout << "Find if Digit Game Can Be Won : " << canAliceWinOptimal(nums) << endl;
    return 0;
}