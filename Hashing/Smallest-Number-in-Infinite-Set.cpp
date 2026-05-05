#include <iostream>
#include <set>
#include <vector>
using namespace std;
class SmallestInfiniteSet
{
    set<int> st;
    int curr;

public:
    SmallestInfiniteSet()
    {
        curr = 1;
    }

    int popSmallest()
    {
        if (st.empty())
        {
            return curr++;
        }

        int val = *st.begin();
        st.erase(val);
        return val;
    }

    void addBack(int num)
    {
        if (num < curr)
        {
            st.insert(num);
        }
    }
};

int main()
{
    SmallestInfiniteSet *obj = new SmallestInfiniteSet();
    cout << "Smallest Number in Infinite Set : " << endl;
    int param_1 = obj->popSmallest();
    obj->addBack(2);
    cout << param_1 << endl;
    obj->addBack(1);
    return 0;
}