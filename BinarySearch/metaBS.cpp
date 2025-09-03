#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Function to show the working of Meta binary search
int bsearch(vector<int> A, int key)
{
    int n = A.size();
    int lg = log2(n - 1) + 1;
    int pos = 0;

    for (int i = lg; i >= 0; i--)
    {
        if (A[pos] == key)
        {
            return pos;
        }

        int new_pos = pos | (1 << i);

        if ((new_pos < n) && (A[new_pos] <= key))
        {
            pos = new_pos;
        }
    }

    return ((A[pos] == key) ? pos : -1);
}

int main()
{
    vector<int> A = {-2, 10, 100, 250, 32315};
    cout << bsearch(A, 10) << endl;

    return 0;
}