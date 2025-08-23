#include <iostream>
#include <vector>
using namespace std;

void getString(int n, vector<char> &mat, string &path, int &k, string &answer)
{
    if (path.length() == n)
    {
        k--;
        if (k == 0)
            answer = path;
        return;
    }

    for (int i = 0; i < mat.size(); i++)
    {
        if (!path.empty() && path.back() == mat[i])
            continue;

        path.push_back(mat[i]);
        getString(n, mat, path, k, answer);
        path.pop_back(); // Backtrack

        if (k == 0)
            return;
    }
}

int main()
{
    vector<char> mat = {'a', 'b', 'c'};
    string answer;
    int n = 3, k = 9;
    string path;

    getString(n, mat, path, k, answer);
    cout << answer << endl;
    return 0;
}
