#include <bits/stdc++.h>

typedef long long ll;

std::map<int, int> ctx;
int arr[1000001];

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
        ctx[0] = 1;
        ll ctr = 0;
        int pref = 0;
        for(int i=0;i<n;i++)
        {
            pref += arr[i];
            if(ctx.find(pref) != ctx.end())
            ctr += ctx[pref];
            ctx[pref]++;
        }
        std::cout<<ctr<<"\n";
        ctx.clear();
    }
    return 0;
}