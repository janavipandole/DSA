#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int diaSumBrute(vector<vector<int>> array)
    {
        int n = array.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    sum += array[i][j];
                }
                else if (j == n - i - 1)
                {
                    sum += array[i][j];
                }
            }
        }
        return sum;
    }

    int diaSumOptimal(vector<vector<int>> array)
    {
        int sum = 0;

        int n = array.size();
        for (int i = 0; i < n; i++)
        {
            sum += array[i][i];
            if (i != n - i - 1)
            {
                sum += array[i][n - 1 - i];
            }
        }
        return sum;
    }

    bool isPrime(int digit)
    {
        for (int i = 2; i < digit; i++)
        {
            if (digit % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int largestPrimeOnDia(vector<vector<int>> nums)
    {
        int n = nums.size();
        int largestPrime = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPrime(nums[i][i]))
            {
                largestPrime = max(largestPrime, nums[i][i]);
            }

            if (i != n - i - 1 && isPrime(nums[i][n - 1 - i]))
            {
                largestPrime = max(largestPrime, nums[i][n - 1 - i]);
            }
        }
        return largestPrime;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> nums2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "diaSumBrute sum : " << s.diaSumBrute(nums1) << endl;
    cout << "diaSumBrute sum :" << s.diaSumBrute(nums2) << endl;
    cout << "diaSumOptimal sum : " << s.diaSumOptimal(nums1) << endl;
    cout << "diaSumOptimal sum : " << s.diaSumOptimal(nums2) << endl;
    cout << "largest Prime present on diagonal : " << s.largestPrimeOnDia(nums1) << endl;
    cout << "largest Prime present on diagonal : " << s.largestPrimeOnDia(nums2) << endl;
    return 0;
}