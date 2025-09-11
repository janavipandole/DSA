#include <iostream>
using namespace std;
vector<bool> prefixesDivBy5(vector<int> &nums)
{
    int num = 0;
    vector<bool> result(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        num = (num * 2 + nums[i]) % 5;
        result[i] = num == 0;
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    cout << "Binary Prefix Divisible By 5 : " << endl;
    vector<bool> ans = prefixesDivBy5(nums);

    for (auto n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}