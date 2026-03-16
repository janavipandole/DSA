#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStackBrute
{
public:
    stack<pair<int, int>> st;

    MinStackBrute()
    {
    }

    void push(int val)
    {
        if (st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
    }

    void pop()
    {
        st.pop();
        return;
    }

    int top()
    {
        int ans = st.top().first;
        return ans;
    }

    int getMin()
    {
        int ans = st.top().second;
        return ans;
    }
    bool isEmpty()
    {
        return st.empty();
    }
}; 

class MinStackOptimal
{
public:
    stack<long long> st;
    long long minVal = INT_MAX;

    MinStackOptimal()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            if (val < minVal)
            {
                st.push((long long)2 * val - minVal);
                minVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.top() < minVal)
        {
            minVal = 2 * minVal - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.top() < minVal)
        {
            return minVal;
        }
        return st.top();
    }

    int getMin()
    {
        return minVal;
    }
    bool isEmpty()
    {
        return st.empty();
    }
};
int main()
{
    MinStackOptimal *ms = new MinStackOptimal();
    cout << "Min Stack : " << endl;
    ms->push(5);
    ms->push(2);
    ms->push(1);
    ms->push(4);
    ms->push(3);

    while (!ms->isEmpty())
    {
        cout << ms->top() << " " << ms->getMin() << endl;
        ms->pop();
    }
    return 0;
}