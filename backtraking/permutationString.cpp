#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

void getPermutations(string &s, vector<string> &answer, int index)
{
    if (index == s.size())
    {
        answer.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        // Skip duplicate characters
        if (i != index && s[i] == s[index]) continue;

        swap(s[i], s[index]);
        getPermutations(s, answer, index + 1);
        swap(s[i], s[index]); // Backtrack
    }
}

vector<string> findPermutation(string &s)
{
    vector<string> answer;
    sort(s.begin(), s.end()); // Sort to ensure duplicates are adjacent
    getPermutations(s, answer, 0);
    return answer;
}

int main()
{
    string s = "QBTQ";
    vector<string> answer = findPermutation(s);

    for (auto val : answer)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
