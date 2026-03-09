#include <iostream>
using namespace std;

class FrontMiddleBackQueue
{

    /**
     * Your FrontMiddleBackQueue object will be instantiated and called as such:
     * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
     * obj->pushFront(val);
     * obj->pushMiddle(val);
     * obj->pushBack(val);
     * int param_4 = obj->popFront();
     * int param_5 = obj->popMiddle();
     * int param_6 = obj->popBack();
     */
    vector<int> nums;

public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        nums.insert(nums.begin(), val);
    }

    void pushMiddle(int val)
    {
        nums.insert(nums.begin() + (nums.size() / 2), val);
    }

    void pushBack(int val)
    {
        nums.push_back(val);
    }

    int popFront()
    {
        if (nums.size() == 0) return -1;
        int ans = nums[0];
        nums.erase(nums.begin());
        return ans;
    }

    int popMiddle()
    {
        if (nums.size() == 0) return -1;
        int mid = (nums.size() - 1) / 2;
        int ans = nums[mid];

        nums.erase(nums.begin() + mid);
        return ans;
    }

    int popBack()
    {
        if (nums.size() == 0) return -1;
        int ans = nums[nums.size() - 1];
        nums.pop_back();
        return ans;
    }
};

int main()
{
    FrontMiddleBackQueue* FMBQueue = new FrontMiddleBackQueue();

    cout<<"Design Front Middle Back Queue : "<<endl;

    FMBQueue->pushFront(1);
    FMBQueue->pushBack(2);
    FMBQueue->pushBack(3);
    FMBQueue->pushMiddle(4);

    cout<<FMBQueue->popFront()<<endl;

    cout<<FMBQueue->popFront()<<endl;

    cout<<FMBQueue->popMiddle()<<endl;

    cout<<FMBQueue->popBack()<<endl;

    return 0;
}