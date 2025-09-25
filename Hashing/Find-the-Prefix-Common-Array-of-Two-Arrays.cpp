#include <iostream>
#include <map>
using namespace std;
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> freq(n+1, 0);
    vector<int> ans(n, 0);
    int commonCount = 0;

    for (int i = 0; i < n; ++i) {
        if (++freq[A[i]] == 2) commonCount++;

        if (++freq[B[i]] == 2) commonCount++;

        ans[i] = commonCount;
    }

    return ans;
}
int main()
{
    vector<int> A = {1,3,2,4}, B = {3,1,2,4};
    vector<int> ans = findThePrefixCommonArray(A, B);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}