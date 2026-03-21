#include <iostream>
using namespace std;
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int index;

public:
    KthLargest(int k, vector<int> &nums)
    {
        index = k;
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > index)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main()
{
    vector<int> nums = {7, 7, 7, 7, 8, 3};
    int k = 4;
    KthLargest *obj = new KthLargest(k, nums);
    cout << "Kth Largest Element in a Stream : " << endl;
    cout << obj->add(2) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(9) << endl;

    return 0;
}