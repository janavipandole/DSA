#include <iostream>
#include <unordered_set>
using namespace std;
// Brute force solution
int findFinalValueBrute(vector<int> &nums, int original)
{
    unordered_set<int> s;

    for (int x : nums)
    {
        s.insert(x);
    }
    for (int x : nums)
    {
        if (s.find(original) != s.end())
        {
            original *= 2;
        }
    }
    return original;
}
// Optimal solution
int findFinalValueOptimal(vector<int> &nums, int original)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] == original)
        {
            original *= 2;
            i = 0;
            continue;
        }
        i++;
    }
    return original;
}
int main()
{
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;
    cout << "Keep Multiplying Found Values by Two : " << findFinalValueBrute(nums, original) << endl;
    cout << "Keep Multiplying Found Values by Two : " << findFinalValueOptimal(nums, original) << endl;
    return 0;
}