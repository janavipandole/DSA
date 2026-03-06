#include <iostream>
#include <vector>
#include <stack>
using namespace sstd;
class BrowserHistory
{
    vector<string> current_Pages;
    stack<string> back_history, ;
    stack<string> forward_history;
    int x;

public:
    BrowserHistory(string homepage)
    {
        current_Pages.push_back(homepage);
        x++;
    }

    void visit(string url)
    {
        current_Pages.push_back(url);
        x++;
    }

    string back(int steps)
    {
        string ans;
        if (steps > x)
        {
            for (int i = current_Pages.size() - 1; i >= 0 && step <= current_Pages.size(); i--)
            {
                back_history.push(current_Pages[i]);
                current_Pages.pop();
                ans = current_Pages[i];
            }
        }
        return ans;
    }

    string forward(int steps)
    {
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
int main()
{
    cout << "Design Browser History : " << endl;
    BrowserHistory *obj = new BrowserHistory(homepage);
    obj->visit("facebook.com");
    obj->visit("google.com");
    obj->visit("instagram.com");
    obj->visit(url);
    string param_2 = obj->back(2);
    string param_3 = obj->forward(1);
    return 0;
}