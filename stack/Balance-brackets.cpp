#include <iostream>
using namespace std;

string isBalanced(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        else
        {
            if (s.size() == 0)
                return "NO";
            else
            {
                if ((s.top() == '(' && expression[i] == ')') ||
                    (s.top() == '{' && expression[i] == '}') ||
                    (s.top() == '[' && expression[i] == ']')){
                    s.pop();
                }
            }
        }
    }
    return s.size() == 0 ? "YES":"NO";
}
int main()
{
    cout<<"Balanced Brackets : "<<endl;
    int t;
    cin >> t;
    cin.ignore(); 

    for (int i = 0; i < t; i++)
    {
        string expression;
        getline(cin, expression);

        string result = isBalanced(expression);
        cout << result << endl;
    }

    return 0;
}