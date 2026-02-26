#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 + num1);
            }
            else if (tokens[i] == "-")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            }
            else if (tokens[i] == "*")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 * num1);
            }
            else if (tokens[i] == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 / num1);
            }
            else
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
int main()
{
    Solution s;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Evaluate Reverse Polish Notation : " << s.evalRPN(tokens) << endl;

    return 0;
}