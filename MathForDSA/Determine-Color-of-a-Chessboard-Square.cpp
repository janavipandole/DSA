#include <iostream>
using namespace std;

class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        int num1 = coordinates[0] - 'a' + 1;
        int num2 = coordinates[1] - '0';

        return (num1 + num2) % 2 == 1;
    }
};
int main()
{
    Solution s;
    string coordinates = "h3";
    cout << "Determine Color of a Chessboard Square : " << s.squareIsWhite(coordinates) << endl;
    return 0;
}