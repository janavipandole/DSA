#include <iostream>
using namespace std;
int getFirstSetBit(int n)
{
    int index = 0;
    while(n > 0){
        index++;
        if(n % 2 == 1) return index;

        n /= 2;
    }
    return index;
}
int main()
{
    cout << "First Set Bit : " << getFirstSetBit(12) << endl;
    return 0;
}