#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, vector<string>> mpp;
    while (n--)
    {
        string name;
        cin >> name;
        int mark;
        cin >> mark;
        mpp[mark].push_back(name);
    }

    for (auto info = mpp.rbegin(); info != mpp.rend(); info++)
    {
        sort(info->second.begin(), info->second.end());
        for (auto name : info->second)
        {
            cout << name << " " << info->first << endl;
        }
    }
    return 0;
}