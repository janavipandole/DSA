#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size()) return false;

    unordered_map<char, char> mapping;
    unordered_set<char> used;

    for (int i = 0; i < s.size(); ++i)
    {
        char sc = s[i], tc = t[i];

        if (mapping.count(sc))
        {
            if (mapping[sc] != tc) return false;
        }
        else
        {
            if (used.count(tc)) return false;
            mapping[sc] = tc;
            used.insert(tc);
        }
    }

    return true;
}
int main()
{
    string s = "bbbaaaba", t = "aaabbbba";
    cout << "Isomorphic Strings : " << isIsomorphic(s, t) << endl;
    return 0;
}