#include <iostream>
using namespace std;

bool firstRow(char ch)
{
    ch = tolower(ch);
    return ch == 'q' || ch == 'w' || ch == 'e' || ch == 'r' || ch == 't' || ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'p';
}
bool secondRow(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 's' || ch == 'd' || ch == 'f' || ch == 'g' || ch == 'h' || ch == 'j' || ch == 'k' || ch == 'l';
}
bool thirdRow(char ch)
{
    ch = tolower(ch);
    return ch == 'z' || ch == 'x' || ch == 'c' || ch == 'v' || ch == 'b' || ch == 'n' || ch == 'm';
}
vector<string> findWords(vector<string> &words)
{
    vector<string> ans;

    for (int i = 0; i < words.size(); i++)
    {
        int first = 0, second = 0, third = 0;
        for (int j = 0; j < words[i].size(); j++)
        {
            if (firstRow(words[i][j]))
                first++;
            else if (secondRow(words[i][j]))
                second++;
            else if (thirdRow(words[i][j]))
                third++;
        }
        if (first == words[i].size())
            ans.push_back(words[i]);
        else if (second == words[i].size())
            ans.push_back(words[i]);
        else if (third == words[i].size())
            ans.push_back(words[i]);
    }
    return ans;
}
int main()
{
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    cout << "Keyboard Row : " << endl;
    vector<string> answer = findWords(words);
    for (auto ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}