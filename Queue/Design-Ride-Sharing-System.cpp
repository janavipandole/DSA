#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class RideSharingSystem
{
    queue<int> Rider;
    queue<int> Driver;
    unordered_set<int> cancelRid;

public:
    RideSharingSystem(){}

    void addRider(int riderId)
    {
        if(cancelRid.count(riderId)) cancelRid.erase(riderId);   // new request, remove old cancel

        Rider.push(riderId);
    }

    void addDriver(int driverId)
    {
        Driver.push(driverId);
    }

    vector<int> matchDriverWithRider()
    {
        while(!Rider.empty() && cancelRid.count(Rider.front())) Rider.pop();

        if(Rider.empty() || Driver.empty()) return {-1,-1};

        int rider = Rider.front();
        int driver = Driver.front();

        Rider.pop();
        Driver.pop();

        return {driver,rider};
    }

    void cancelRider(int riderId)
    {
        cancelRid.insert(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */


int main()
{
    cout <<"Design Ride Sharing System : " << endl;
    RideSharingSystem *RideSystem = new RideSharingSystem();

    RideSystem->addRider(3);
    RideSystem->addDriver(2);
    RideSystem->addRider(1);

    vector<int> ans1 = RideSystem->matchDriverWithRider();
    cout<<ans1[0]<<" "<<ans1[1]<<endl;

    RideSystem->cancelRider(2);
    
    vector<int> ans2 = RideSystem->matchDriverWithRider();
    cout<<ans2[0]<<" "<<ans2[1]<<endl;
    return 0;
}