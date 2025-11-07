#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        double r1 = (double)a[0] / a[1];
        double r2 = (double)b[0] / b[1];
        return r1 > r2;
    }
    double fractionalKnapsack(vector<int> &arr, vector<int> &wt, int capacity)
    {
        vector<vector<int>> val;

        for (int i = 0; i < arr.size(); i++)
        {
            val.push_back({arr[i], wt[i]});
        }
        sort(val.begin(), val.end(), comp);

        double TotalVal = 0;
        for (int i = 0; i < val.size(); i++)
        {
            if (val[i][1] <= capacity)
            {
                capacity -= val[i][1];
                TotalVal += val[i][0];
            }
            else
            {
                double value = ((double)val[i][0] / (double)val[i][1]);
                value *= capacity;
                TotalVal += value;
                break;
            }
        }
        return TotalVal;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {8, 2, 10, 1, 9, 7, 2, 6, 4, 9}, wt = {10, 1, 7, 7, 5, 1, 8, 6, 8, 7};
    int capacity = 21;
    cout << "Fractional Knapsack : " << s.fractionalKnapsack(arr, wt, capacity) << endl;
    return 0;
}