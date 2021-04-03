#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<int> G[100001];
int degx[100001];

int main(void)
{
    int n;
    ll s;
    std::cin>>n>>s;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        std::cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
        degx[a]++;
        degx[b]++;
    }
    ll cz = 0;
    for(int i=1;i<=n;i++)
    {
        if(degx[i] == 1)
        cz++;
    }
    long double ax = ((long double)s/(long double)cz) * 2;
    printf("%.10Lf\n", ax);
    return 0;
}