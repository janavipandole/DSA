#include <iostream>
using namespace std;
vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    vector<pair<int, int>> scoreWithIndex;
    for (int i = 0; i < n; ++i)
    {
        scoreWithIndex.push_back({score[i], i});
    }

    sort(scoreWithIndex.rbegin(), scoreWithIndex.rend()); 

   vector<string> ans(n);
    for (int rank = 0; rank < n; rank++) {
        int idx = scoreWithIndex[rank].second;
        if (rank == 0) ans[idx] = "Gold Medal";
        else if (rank == 1) ans[idx] = "Silver Medal";
        else if (rank == 2) ans[idx] = "Bronze Medal";
        else ans[idx] = to_string(rank + 1);
    }

    return ans;
}
int main()
{
    vector<int> score = {10, 3, 8, 9, 4};
    vector<string> ans = findRelativeRanks(score);
    for (auto rank : ans)
    {
        cout << rank << " ";
    }
    cout << endl;
    return 0;
}