#include <iostream>
#include <vector>
using namespace std;

int maximum69NumberBruteForce(int num)
{
    int maximumNumber = num;
    vector<int> nums;
    while (num > 0)
    {
        nums.push_back(num % 10);
        num /= 10;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 6)
        {
            nums[i] = 9;
            int number = 0;
            for (int j = nums.size() - 1; j >= 0; j--)
            {
                number += nums[j];
                number *= 10;
                
            }
            number /= 10;
            maximumNumber = max(maximumNumber, number);
            nums[i] = 6;
        }
    }
    return maximumNumber;
}

int maximum69NumberOptimal(int num){
    string newNum = to_string(num);

    for(auto &ch : newNum){
        if(ch == '6'){
            ch = '9';
            break;
        }
    }
    return stoi(newNum);
}

int main()
{
    cout << "maximum Number : " << maximum69NumberOptimal(9669);
    cout << endl;
    return 0;
}