#include <iostream>
using namespace std;
class Solution
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end());
        long long sum = 0;
        for (int i = 1; i < salary.size() - 1; i++)
        {
            sum += salary[i];
        }
        double ans = double(sum) / (salary.size() - 2);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> salary = {48000, 59000, 99000, 13000, 78000, 45000, 31000, 17000, 39000, 37000, 93000, 77000, 33000, 28000, 4000, 54000, 67000, 6000, 1000, 11000};
    cout << "Average Salary Excluding the Minimum and Maximum Salary : " << s.average(salary) << endl;
    return 0;
}