#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    cout << "The Monk and Class Marks" << endl;
    int n;
    cin >> n;
    map<int, multiset<string>> mpp;
    while (n--)
    {
        string name;
        cin >> name;
        int mark;
        cin >> mark;
        mpp[mark].insert(name);
    }

    for (auto info = mpp.rbegin(); info != mpp.rend(); info++)
    {
        for (auto name : info->second)
        {
            cout << name << " " << info->first << endl;
        }
    }
    return 0;
}