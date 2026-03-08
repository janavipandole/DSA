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
        if (st1.empty())
        {
            st1.push(x);
            return ;
        }
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop()
    {
        int ans = st1.top();
        st1.pop();
        return ans;
    }

    int peek()
    {
        int ans = st1.top();
        return ans;
    }

    bool empty()
    {
        return st1.empty();
    }
};

int main()
{
    MyQueue *qu = new MyQueue();
    qu->push(1);
    qu->push(2);
    qu->push(3);
    qu->push(4);

    cout << "Implement Queues using Stack : " << endl;
    while (!qu->empty())
    {
        cout << qu->peek() << " ";
        qu->pop();
    }
    cout << endl;
    return 0;
}