#include <iostream>
using namespace std;
int computeModulus(int n, int d)
{
    return n & (d-1);
}
int main()
{
    cout << "Compute Modulus : " << computeModulus(10, 4) << endl;
    return 0;
}