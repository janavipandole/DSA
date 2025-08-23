#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end)
{

    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}
void palindromPartition(string s, vector<vector<string>> &result, vector<string> &path, int index)
{
    if (index == s.size())
    {
        result.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            palindromPartition(s, result, path, i + 1);
            path.pop_back();
        }
    }
}
int main()
{
    string s = "aabb";
    vector<vector<string>> result;
    vector<string> path;

    palindromPartition(s, result, path, 0);

    for (auto res : result)
    {
        cout << "[";
        for (auto str : res)
        {
            cout << "'" << str << "'" << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}