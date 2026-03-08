#include <iostream>
#include <stack>
using namespace std;
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyQueue
{
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
    }

    int pop()
    {
    }

    int peek()
    {
    }

    bool empty()
    {
    }
};

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}