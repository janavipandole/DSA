#include <iostream>
#include <vector>
using namespace std;

class QueueArray
{
    int *nums;
    int sizeNums, start, end, capcity;

public:
    QueueArray(int k)
    {
        capcity = k;
        nums = new int[capcity];
        sizeNums = 0;
        start = 0;
        end = -1;
    }

    bool push(int val)
    {
        if (sizeNums == capcity)
            return false;

        end++;
        nums[end] = val;
        sizeNums++;
        return true;
    }

    bool pop()
    {
        if (sizeNums == 0 || start > end)
            return false;

        nums[start] = -1;
        start++;
        sizeNums--;
        return true;
    }

    int top()
    {
        return isEmpty() ? -1 : nums[start];
    }

    bool isEmpty()
    {
        return sizeNums == 0;
    }

    bool isFull()
    {
        return sizeNums == capcity;
    }
};

int main()
{
    QueueArray *queue = new QueueArray(5);

    cout << "Implementation of Queue using Array : " << endl;

    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);

    while (!queue->isEmpty())
    {
        cout << queue->top() << " ";
        queue->pop();
    }
    cout << endl;

    return 0;
}