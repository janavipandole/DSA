#include <iostream>
using namespace std;
// Optimal solution
int hIndexOptimal(vector<int> &citations)
{
    int n = citations.size();
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (citations[mid] == (n - mid))
        {
            return citations[mid];
        }
        else if (citations[mid] > (n - mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return n - low;
}

int main()
{
    vector<int> citations = {3, 0, 6, 1, 5};
    sort(citations.begin(), citations.end());
    cout << "h Index : " << hIndexOptimal(citations) << endl;

    return 0;
}