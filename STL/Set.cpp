#include <iostream>
#include <set>
using namespace std;
void getSet(set<string> &s)
{
    cout << "Size : " << s.size() << endl;
    for (auto val : s)
    {
        cout << val << endl;
    }
}
int main()
{
    set<string> s; // decleartion
    s.insert("a");
    s.insert("c");
    s.insert("b");
    s.insert("e");
    s.insert("d");
    s.insert("f");
    getSet(s);
    s.erase("a");
    getSet(s);
    auto it = s.find("b");
    cout << (*it) << endl;
    s.clear();
    getSet(s);
    return 0;
}