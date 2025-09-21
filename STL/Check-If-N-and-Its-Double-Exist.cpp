#include <iostream>
#include <unordered_set>
using namespace std;
// brute force solution
bool checkIfExistBrute(vector<int> &nums)
{
    unordered_set<int> s;
    int zeroCount = 0;
    for (auto num : nums)
    {
        if (num == 0)
            zeroCount++;
        s.insert(num);
    }
    if (zeroCount >= 2)
        return true;
    for (auto num : s)
    {
        if (num != 0 && s.find(2 * num) != s.end())
            return true;
    }
    return false;
}
// Optimal solution
bool checkIfExistOptimal(vector<int> &arr)
{
    unordered_set<int> s;

    for (int x : arr)
    {
        if (s.find(2 * x) != s.end() || (x % 2 == 0 && s.find(x / 2) != s.end()))
        {
            return true;
        }
        s.insert(x);
    }
    return false;
}
int main()
{
    vector<int> num = {0, -2, 2};
    cout << "Check If N and Its Double Exist : " << checkIfExistBrute(num) << endl;
    cout << "Check If N and Its Double Exist : " << checkIfExistOptimal(num) << endl;
    return 0;
}
