#include <iostream>
#include <vector>
using namespace std;

string reverseStr(string s, int k)
{
    int index = -1;
    for (int i = 0; i < s.size(); i += 2 * k)
    {
        int end = min(i + k, (int)s.size());
        reverse(s.begin() + i, s.begin() + end);
    }
    return s;
}

int main()
{
    string s = "abcdefg";
    int k = 2;
    cout << "reverseStr : " << reverseStr(s, k) << endl;
    return 0;
}