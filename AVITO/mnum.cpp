#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 200001

typedef long long ll;

std::vector<std::pair<int, int> > arr[CHOR];
int sq[CHOR];
ll xd[CHOR];

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=1;i<CHOR;i++)
    {
        if(2*i + 1 > CHOR)
        break;
        for(ll j=i+1;(1LL*j*j - 1LL*i*i)<CHOR;j++)
        arr[1LL*j*j - 1LL*i*i].pb(mp(i, j));
    }
    for(int i=2;i<=n;i+=2)
    std::cin>>xd[i];
    bool ok = 0;
    for(int i=2;i<=n;i+=2)
    {
        for(auto v : arr[xd[i]])
        {
            if(sq[i-2] < v.first)
            {
               sq[i-1] = v.first;
               sq[i] = v.second;
               break;
            }
        }
        if(!sq[i-1])
        {
           ok = 1;
           break;
        }
    }
    if(ok)
    std::cout<<"No\n";
    else
    {
       std::cout<<"Yes\n";
       for(int i=1;i<=n;i++)
       {
          xd[i] = 1LL*sq[i]*sq[i] - 1LL*sq[i-1]*sq[i-1];
          std::cout<<xd[i]<<" ";
       }
       std::cout<<"\n";
    }
    return 0;
}
