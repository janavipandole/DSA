#include <iostream>
#include <math.h>
using namespace std;
int kthElement(vector<int> &n1, vector<int> &n2, int k)
{
    int cnt = 0, i = 0, j = 0;
    k = k -1;

    while (i < n1.size() && j < n2.size())
    {
        if (n1[i] < n2[j])
        {
            if (cnt == k)
                return n1[i];
            i++;
            cnt++;
        }
        else
        {
            if (cnt == k)
                return n2[j];
            j++;
            cnt++;
        }
    }
    while (i < n1.size() && j < n2.size())
    {
        if (cnt == k)
            return n2[j];
        j++;
        cnt++;
    }
    while (i < n1.size())
    {
        if (cnt == k)
            return n1[i];
        i++;
        cnt++;
    }
    return -1;
}

int main()
{
    vector<int> n1 = {1, 4, 8, 10, 12}, n2{5, 7, 11, 15, 17};
    int k = 6;
    cout << "kth Element : " << kthElement(n1, n2, k) << endl;
    return 0;
}