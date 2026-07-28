#include <iostream>
using namespace std;

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> &employees, int id)
    {
        unordered_map<int, Employee *> mp;

        for (auto emp : employees)
        {
            mp[emp->id] = emp;
        }

        int totalImp = 0;
        queue<int> q;
        q.push(id);

        while (!q.empty())
        {
            auto currId = q.front();
            q.pop();

            Employee *emp = mp[currId];
            totalImp += emp->importance;

            for(int sub : emp->subordinates){
                q.push(sub);
            }
        }

        return totalImp;
    }
};
int main()
{
    // employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]],
    vector<Employee *> employees;

    Employee *E = new Employee();
    E->id = 1;
    E->importance = 5;
    E->subordinates = {2, 3};
    employees.push_back(E);

    E = new Employee();
    E->id = 2;
    E->importance = 3;
    employees.push_back(E);

    E = new Employee();
    E->id = 3;
    E->importance = 3;
    employees.push_back(E);

    int id = 1;

    Solution s;
    cout << "Employee Importance : " << s.getImportance(employees, id) << endl;
    return 0;
}