#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return;
    }
    int temp = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        cout << arr[i] << " ";
        arr[i + 1] = arr[i];
    }
    cout << endl;
    arr[0] = temp;
}

void rotate2(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // Handles cases where k > n

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout << "Original array: ";
    rotate2(nums, 3);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}