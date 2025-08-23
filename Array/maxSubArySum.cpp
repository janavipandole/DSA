#include <iostream>
#include <vector>
using namespace std;

int maxSubArySum(const vector<int> &arr)
{
    int maxSum = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        int currentSum = 0;
        for (int j = i; j < arr.size(); ++j)
        {
            currentSum += arr[j];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {1, -2, 3, 4, -5, 6};
    cout << "Maximum subarray sum is: " <<  maxSubArySum(arr) << endl;
    return 0;
}