#include <bits/stdc++.h>

typedef long long ll;

ll arr[1000001];
std::map<ll, int> mii;

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        std::cin>>arr[i];
        mii[0] = 1;
        ll pref = 0;
        ll ctx = 0;
        for(int i=0;i<n;i++)
        {
            pref += arr[i];
            if(mii.find(pref - 47) != mii.end())
            ctx += mii[pref - 47];
            mii[pref]++;
        }
        std::cout<<ctx<<"\n";
        mii.clear();
    }
    return 0;
}