#include <iostream>
#include <queue>
using namespace std;

class RecentCounter
{
    queue<int> data;
    int calls;

public:
    RecentCounter()
    {
        calls = 0;
    }

    int ping(int t)
    {
        data.push(t);
        calls++;

        while (data.front() < (t - 3000))
        {
            data.pop();
            calls--;
        }
        return calls;
    }
};

int main()
{
    cout << "Number of Recent Calls : " << endl;
    RecentCounter *calls = new RecentCounter();
    cout << calls->ping(642) << endl;
    cout << calls->ping(1849) << endl;
    cout << calls->ping(4921) << endl;
    cout << calls->ping(5936) << endl;
    cout << calls->ping(5957) << endl;
    return 0;
}