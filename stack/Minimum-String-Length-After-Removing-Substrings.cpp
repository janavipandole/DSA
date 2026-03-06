#include <iostream>
using namespace std;
class Solution
{
public:
    int minLength(string s)
    {
        stack<char> st;

        for (int i : s)
        {
            if (!st.empty() && st.top() == 'A' && i == 'B')
            {
                st.pop();
            }
            else if (!st.empty() && st.top() == 'C' && i == 'D')
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        return st.size();
    }
};
int main()
{
    Solution s;
    string str = "ABFCACDB";
    cout << "Minimum String Length After Removing Substrings : "<<s.minLength(str) << endl;
    return 0;
}