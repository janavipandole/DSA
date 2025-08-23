#include <iostream>
using namespace std;

class Stack
{
    int *nums;
    int capacity;
    int top;

public:
    // parameterize constructer
    Stack(int size)
    {
        capacity = size;
        nums = new int[capacity];
        top = -1;
    }
    ~Stack()
    {
        delete[] nums;
    }
    void push(int val)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            nums[++top] = val;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            nums[top--];
        }
    }
    int topElement()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return nums[top];
        }
    }
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    Stack s(5);
    s.push(10); // Pushing elements
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout << s.topElement() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
