#include <bits/stdc++.h>
#define mp std::make_pair
#define OC -100000000001LL
#define EC -100000000002LL

typedef long long ll;

std::pair<ll, ll> memo[100001];
bool vis[100001];
ll arr[100001];

std::pair<ll, ll> rexm(int n)
{
    if(n == 1)
    {
        if(arr[n] & 1)
        return (memo[n] = mp(arr[n], EC));
        else return (memo[n] = mp(OC, arr[n]));
    }
    if(vis[n])
    return memo[n];
    std::pair<ll, ll> p = rexm(n-1);
    ll oa = OC;
    ll ea = EC;
    if(arr[n] & 1)
    {
        if(p.second != EC)
        oa = std::max(p.first, std::max(p.second + arr[n], arr[n]));
        else oa = std::max(p.first, arr[n]);
        if(p.first != OC)
        ea = std::max(p.second, p.first + arr[n]);
        else ea = p.second;
    }
    else
    {
        if(p.second != EC)
        ea = std::max(p.second, std::max(p.second + arr[n], arr[n]));
        else ea = std::max(p.second, arr[n]);
        if(p.first != OC)
        oa = std::max(p.first, p.first + arr[n]);
        else oa = p.first;
    }
    memo[n] = mp(oa, ea);
    vis[n] = 1;
    return memo[n];
}

int main(void)
{
    memset(vis, 0, sizeof(vis));
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    memo[n] = rexm(n);
    std::cout<<memo[n].first<<"\n";
    return 0;
}
