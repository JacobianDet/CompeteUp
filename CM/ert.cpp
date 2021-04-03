#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::map<ll, ll> vals;

ll modexp(ll a, ll n, ll m)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%m) * (a%m))%m;
		a = ((a%m) * (a%m))%m;
		n >>= 1;	
	}
	return res;
}

ll solve(ll a, ll b, ll m) 
{
    ll n = (ll) sqrt (m + .0) + 1;
    for (ll p = n; p >= 1; --p)
    vals[modexp(a, p * n, m)] = p;
    for (ll q = 0; q <= n; ++q) 
    {
        ll cur = (modexp(a, q, m) * b) % m;
        if (vals.count(cur)) 
        {
        	ll ans =  vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,m,p,q;
	std::cin>>n>>m>>p>>q;
	ll dl = (solve(p, q, m) % (m - 1));
	if(!dl)
	dl += (m - 1);	
	std::cout<<dl<<" ";
	for(int i=0;i<n-1;i++)
	std::cout<<"1 ";
	std::cout<<"\n";	
	return 0;
}