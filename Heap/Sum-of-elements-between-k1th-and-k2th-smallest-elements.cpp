#include <iostream>
using namespace std;
class Solution
{
public:
    long long sumBetweenTwoKth(long long nums[], long long N, long long k1, long long k2)
    {

       priority_queue<long long> maxHeap;
        long long ans = 0;
        for (int i = 0; i < N; i++)
        {
            maxHeap.push(nums[i]);
            if(maxHeap.size() > k2-1){
                maxHeap.pop();
            }
        }

        while(maxHeap.size() > k1){
            ans += maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    long long n = 7, nums[] = {20, 8, 22, 4, 12, 10, 14}, k1 = 3, k2 = 6;
    cout << "Sum of elements between k1'th and k2'th smallest elements : " << s.sumBetweenTwoKth(nums, n, k1, k2) << endl;
    return 0;
}