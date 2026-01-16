#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

class Solution
{
public:
    string interpret(string command)
    {
        string ans = "";
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'G')
            {
                ans += 'G';
            }
            else if (command[i] == '(' && command[i + 1] == 'a')
            {
                ans += 'a';
                ans += 'l';
                i += 3;
            }
            else
            {
                ans += 'o';
                i++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string command = "G()()()()(al)";
    cout << "Goal Parser Interpretation : " << s.interpret(command) << endl;
    return 0;
}