#include <iostream>
using namespace std;
int findNumbers(vector<int> &nums)
{
    int count = 0;

    for (auto num : nums)
    {
        int digit = 0;
        while (num > 0)
        {
            digit++;
            num /= 10;
        }
        if(digit % 2 == 0) count++;
    }
    return count;
}
int main()
{
    vector<int> nums = {555,901,482,1771};
    cout << "Find Numbers with Even Number of Digits : " << findNumbers(nums) << endl;
    return 0;
}