#include <iostream>
using namespace std;

class cricular_queue
{
    int *nums;
    int sizeNums, start, end, capcity;

public:
    cricular_queue(int size)
    {
        capcity = size;
        nums = new int[capcity];
        sizeNums = 0;
        start = 0;
        end = -1;
    }
    void push(int val)
    {
        if (sizeNums == capcity)
        {
            cout << "Circular Queue FULL : " << endl;
            return;
        }
        end = (end + 1) % capcity;
        nums[end] = val;
        sizeNums++;
    }

    void pop()
    {
        if (sizeNums == 0)
        {
            cout << "Empty  Cricular Queue : " << endl;
            return;
        }
        nums[start] = -1;
        start = (start + 1) % capcity;
        sizeNums--;
    }
    int front()
    {
        if (sizeNums == 0)
        {
            cout << "Empty  Cricular Queue : " << endl;
            return -1;
        }
        return nums[start];
    }
    bool empty()
    {
        return sizeNums == 0;
    }
};

int main()
{
    cricular_queue cq(4);
    cout << "Implementation of Cricular Queue using array : " << endl;
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    while (!cq.empty())
    {
        cout << cq.front() << " ";
        cq.pop();
    }
    cout << endl;

    return 0;
}