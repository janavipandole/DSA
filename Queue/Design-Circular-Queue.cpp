#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
    int *nums;
    int sizeNums, start, end, capcity;

public:
    MyCircularQueue(int size)
    {
        capcity = size;
        nums = new int[capcity];
        sizeNums = 0;
        start = 0;
        end = -1;
    }

    bool enQueue(int value)
    {
        if (sizeNums == capcity) return false;

        end = (end + 1) % capcity;
        nums[end] = value;
        sizeNums++;
        return true;
    }

    bool deQueue()
    {
        if (sizeNums == 0) return false;
        nums[start] = -1;
        start = (start + 1) % capcity;
        sizeNums--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : nums[start];
    }
    
    int Rear() {
        return isEmpty() ? -1 : nums[end];
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

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    cout << "Design Circular Queue : " << endl;
    MyCircularQueue *Cq = new MyCircularQueue(5);
    Cq->enQueue(1);
    Cq->enQueue(2);
    Cq->enQueue(3);
    Cq->enQueue(4);
    Cq->enQueue(5);
    cout << "Is Circular Queue full : " << Cq->isFull() << endl;

    cout << "Front element : " << Cq->Front() << endl;
    cout << "Rear element : " << Cq->Rear() << endl;

    while (!Cq->isEmpty())
    {
        cout << Cq->Front() << endl;
        Cq->deQueue();
    }
    return 0;
}