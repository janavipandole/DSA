#include <iostream>
include<vector> using namespace std;
class CustomStack
{
    vector<int> st;
    int maxSize;

public:
    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
    }

    void push(int x)
    {
        if (st.size() < maxSize)
            st.push_back(x);
    }

    int pop()
    {
        if (st.empty())
            return -1;

        int num = st.back();
        st.pop_back();
        return num;
    }

    void increment(int k, int val)
    {
        int update = min(k, st.size())

        for (int i = 0; i < update; i++)
        {
            st[i] += val;
        }
    }
};

int main()
{
    CustomStack st(3);
    cout << "Design a Stack With Increment Operation : " << endl;

    st.push(1);
    st.push(2);

    cout << st.pop() << endl;   // 2

    st.push(2);
    st.push(3);
    st.push(4);                 // ignore (stack full)

    st.increment(5, 100);

    cout << st.pop() << endl;   // 103
    cout << st.pop() << endl;   // 102
    cout << st.pop() << endl;   // 101
    cout << st.pop() << endl;   // -1

    return 0;
}