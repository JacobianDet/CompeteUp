#include <bits/stdc++.h>
#define pb push_back
#define MOD 1000000007

typedef long long ll;

std::vector<int> ac, bc;
ll ax[100001];

ll bs1a(int val)
{
    ll lo = 0;
    ll hi = (ll)ac.size() - 1;
    while(lo < hi)
    {
        ll mid = lo + (hi - lo)/2;
        if(ac[mid] < val)
        lo = mid + 1;
        else hi = mid;
    }
    if((lo > hi) || (ac[lo] < val))
    return -1;
    else return lo;
}

ll bs1b(int val)
{
    ll lo = 0;
    ll hi = (ll)bc.size() - 1;
    while(lo < hi)
    {
        ll mid = lo + (hi - lo)/2;
        if(bc[mid] < val)
        lo = mid + 1;
        else hi = mid;
    }
    if((lo > hi) || (bc[lo] < val))
    return -1;
    else return lo;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string s;
    std::cin>>s;
    for(int i=0,j=(int)s.size();i<j;i++)
    {
        if(s[i] == 'a')
        ac.pb(i);
        if(s[i] == 'b')
        bc.pb(i);
    }
    for(int i=(int)ac.size()-1;i>=0;i--)
    {
        ax[i] = 1;
        ll pos1 = bs1b(ac[i]);
        if(pos1 != -1)
        {
            ll pos2 = bs1a(bc[pos1]);
            if(pos2 != -1)
            ax[i] = ((1%MOD) + (ax[pos2]%MOD))%MOD;
        }
        if(i != (int)ac.size()-1)
        ax[i] = ((ax[i]%MOD) + (ax[i+1]%MOD))%MOD;     
    }
    std::cout<<ax[0]<<"\n";
    return 0;
}