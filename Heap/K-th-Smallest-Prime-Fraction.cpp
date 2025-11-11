#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {

        priority_queue<pair<double, vector<int>>> maxHeap;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxHeap.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
                if (maxHeap.size() > k)
                {
                    maxHeap.pop();
                }
            }
        }
        return {maxHeap.top().second[0], maxHeap.top().second[1]};
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 5};
    int k = 3;
    cout << "K-th Smallest Prime Fraction : " << endl;
    vector<int> ans = s.kthSmallestPrimeFraction(nums, k);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}