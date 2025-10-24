#include <iostream>
using namespace std;

string largestGoodInteger(string num)
{
    for (int i = 9; i >= 0; i--)
    {
        string triplet(3, '0' + i); // e.g., "999", "888", ..., "000"
        if (num.find(triplet) != string::npos)
        {
            return triplet;
        }
    }
    return "";
}

int main()
{
    string num = "6777133339";
    cout << "Largest Good Integer : " << largestGoodInteger(num) << endl;
    return 0;
}