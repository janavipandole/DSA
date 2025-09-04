#include <iostream>
using namespace std;

int AND(int n1, int n2)
{
    return n1 & n2;
}

int OR(int n1, int n2)
{
    return n1 | n2;
}

int XOR(int n1, int n2)
{
    return n1 ^ n2;
}

int leftShift(int n1, int n2)
{
    return n1 << n2;
}

int rightShift(int n1, int n2)
{
    return n1 >> n2;
}
int NOT(int n)
{
    return ~(n);
}
int main()
{
    cout << "AND : " << AND(13, 7) << endl;
    cout << "OR : " << OR(13, 7) << endl;
    cout << "XOR : " << XOR(13, 7) << endl;
    cout << "leftShift : " << leftShift(13, 1) << endl;
    cout << "rightShift : " << rightShift(13, 1) << endl;
    cout << "NOT for positive: " << NOT(5) << endl;
    cout << "NOT for negative: " << NOT(-6) << endl;

    return 0;
}