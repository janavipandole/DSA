#include <iostream>
#include <vector>
using namespace std;

class EventManager1
{
    vector<pair<int, int>> Manager;

public:
    EventManager(vector<vector<int>> &events)
    {
        Manager.clear();

        for (int i = 0; i < events.size(); i++)
        {
            Manager.push_back({events[i][0], events[i][1]});
        }
    }

    void updatePriority(int eventId, int newPriority)
    {
        for (auto &val : Manager)
        {
            if (val.first == eventId)
            {
                val.second = newPriority;
                break;
            }
        }
    }

    int pollHighest()
    {
        if (Manager.size() == 0)
            return -1;
        sort(Manager.begin(), Manager.end(), [](pair<int, int> a, pair<int, int> b)
             {
            if (a.second != b.second)return a.second > b.second;
            return a.first < b.first; });

        int val = Manager[0].first;

        Manager.erase(Manager.begin());
        return val;
    }
};

class EventManager2
{
    set<int> st;

public:
    EventManager(vector<vector<int>> &events)
    {
    }

    void updatePriority(int eventId, int newPriority)
    {

    }

    int pollHighest()
    {
    }
};

int main()
{
    vector<vector<int>> events = {{5, 7}, {2, 7}, {9, 4}};
    EventManager *obj = new EventManager2(events);

    cout << "Design Event Manager : " << endl;
    cout << obj->pollHighest() << endl;
    obj->updatePriority(9, 8);
    cout << obj->pollHighest() << endl;
    return 0;
}