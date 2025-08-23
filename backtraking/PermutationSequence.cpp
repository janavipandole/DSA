#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string getPermutationOptimal(int n, int k)
{
    string number;
    for (int i = 1; i <= n; i++)
    {
        number += to_string(i);
    }

    while (k > 0)
    {
        next_permutation(number.begin(), number.end());
        k--;
    }
    return number;
}

string getPermutationBetter(int n, int k)
{
    vector<int> num;
    int fact = 1;

    for (int i = 1; i < n; i++)
    {
        fact *= i;
        num.push_back(i);
    }
    num.push_back(n);

    string answer = "";
    k = k - 1;
    while(true){
        answer += to_string(num[k / fact]);
        num.erase(num.begin() + k / fact);

        if(num.size() == 0) break;

        k %= fact;
        fact /= num.size();
    }
    return answer;
}
int main()
{
    cout << getPermutationBetter(4, 9) << endl;
    return 0;
}