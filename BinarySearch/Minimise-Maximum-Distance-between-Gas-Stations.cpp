#include <iostream>
using namespace std;
// Brute force solution
double minMaxDistBrute(vector<int> &stations, int k)
{
    int n = stations.size();
    if (n < 2)
    {
        return 0.0;
    }
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        double maxLength = -1;
        int maxIndex = -1;
        for (int i = 0; i < n - 1; i++)
        {
            double diff = stations[i + 1] - stations[i];
            double sectionLength = diff / double(howMany[i] + 1);
            if (maxLength < sectionLength)
            {
                maxLength = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }
    double maxLength = -1;
    for (int i = 0; i < stations.size(); i++)
    {
        double diff = stations[i + 1] - stations[i];
        double sectionLength = diff / double(howMany[i] + 1);
        maxLength = max(maxLength, sectionLength);
    }
    return maxLength;
}

// Better solution using priority queue
double minMaxDistBetter(vector<int> &stations, int k)
{
    int n = stations.size();
    // edge case
    if (n < 2)
    {
        return 0.0;
    }
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({stations[i + 1] - stations[i], i});
    }
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();
        howMany[tp.second]++;
        double diff = stations[tp.second + 1] - stations[tp.second];
        double sectionLength = diff / (double)(howMany[tp.second] + 1);
        pq.push({sectionLength, tp.second});
    }

    return pq.top().first;
}
// optimal solution using BS
int numberOfGasStations(double dist, vector<int> &stations)
{
    int cnt = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        int numberInBetween = ((stations[i] - stations[i - 1]) / dist);
        if (((stations[i] - stations[i - 1]) / dist) == numberInBetween * dist)
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}
double minMaxDistOptimal(vector<int> &stations, int k)
{
    int n = stations.size();
    // edge case
    if (n < 2)
    {
        return 0.0;
    }
    double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (double)(stations[i + 1] - stations[i]));
    }

    double diff = 1e-6;
    while (high - low > diff)
    {
        double mid = (low + high) / (2.0);
        int cnt = numberOfGasStations(mid, stations);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}
int main()

{
    vector<int> stations = {1, 2, 3, 4, 5};
    int k = 2;
    cout << "minMaxDist : " << minMaxDistOptimal(stations, k) << endl;
    return 0;
}