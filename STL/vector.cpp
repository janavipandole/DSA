#include <iostream>
using namespace std;
void print(vector<string> &str)
{
    for (auto s : str)
    {
        cout << s << " ";
    }
    cout << endl;
}
int main()
{
    vector<string> str;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
    }
    print(str);
    return 0;
}