#include <iostream>
#include <queue>
using namespace std;
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
        {
            q1.push(x);
            return ;
        }

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int num = q1.front();
        q1.pop();
        return num;
    }

    int top()
    {
        int num = q1.front();
        return num;
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack *st = new MyStack();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);

    cout << "Implement Stack using Queues : " << endl;
    while (!st->empty())
    {
        cout << st->top() << " ";
        st->pop();
    }
    cout << endl;
    return 0;
}