#include <iostream>
#include <map>

using namespace std;

void print(map<int, string> &m)
{
    cout << m.size() << endl;
    // Print TC = O(logn);
    for (auto &[key, value] : m)
    {
        cout << key << " " << value << endl;
    }
}
int main()
{
    // Create
    map<int, string> m;

    // Update TC = O(logn);
    m.insert({3, "Manoj"});
    m.insert({4, "Rahul"});
    m.insert({5, "Nikhil"});
    m[1] = "Janavi";
    m[2] = "Bali";

    // Delete key value pair in map
    m.erase(5);
    print(m);

    // using find funtion in map
    auto it = m.find(1);
    if (it == m.end())
        cout << "Not found value :) " << endl;
    else
        cout << it->first << " " << it->second << endl;
        
    // clear key value pair in map
    m.clear();
    print(m);

    return 0;
}