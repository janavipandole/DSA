#include <iostream>
using namespace std;

int main()
{
    // creation
    pair<int, string> info1, info2;

    info1 = make_pair(19, "janavi"); // updation
    cout << info1.first << " " << info1.second << endl;

    info2 = {45, "Bali"};
    cout << info2.first << " " << info2.second << endl;

    pair<int, double> p_array[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> p_array[i].first >> p_array[i].second;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << p_array[i].first << " " << p_array[i].second << endl;
    }
    return 0;
}