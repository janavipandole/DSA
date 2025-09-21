#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        multiset<long long> bags;

        for (int i = 0; i < N; ++i)
        {
            long long candy;
            cin >> candy;
            bags.insert(candy);
        }
        long long maxCandy = 0;
        for (int i = 0; i < K; ++i)
        {
            auto it = (--bags.end());
            long long candy = *it;
            maxCandy += candy;
            bags.erase(it);
            bags.insert(candy / 2);
        }
        cout << "Monk and the Magical Candy Bags : " << maxCandy << endl;
    }
    return 0;
}