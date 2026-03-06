#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> nums;

        // "5","-2","4","C","D","9","+","+"
        for (auto operation : operations)
        {
            if (operation == "C")
            {
                nums.pop();
            }
            else if (operation == "D")
            {
                int num = nums.top();
                nums.push(2 * num);
            }
            else if (operation == "+")
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();

                nums.push(num2);
                nums.push(num1);
                nums.push(num1 + num2);
            }
            else
            {
                
                nums.push(stoi(operation));
            }
        }
        int sum = 0;
        while (nums.size() > 0)
        {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    cout << "Baseball Game : " << s.calPoints(ops) << endl;
    return 0;
}