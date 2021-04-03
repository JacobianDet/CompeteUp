#include <bits/stdc++.h>
#define pb push_back
#define MOD 1000000007

typedef long long ll;

int arr[100001];
ll cx[1000001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
	cx[0] = 1;
    for(int i=1;i<=n;i++)
    {
    	std::vector<int> V;
    	for(int j=1;j*j<=arr[i];j++)
    	{
    		if(!(arr[i] % j))
    		{
    			if(j*j == arr[i])
    			V.pb(j);
    			else
    			{
    				V.pb(j);
    				V.pb(arr[i]/j);
    			}	
    		}	
    	}
    	std::sort(V.rbegin(), V.rend());
    	for(auto u : V)
    	cx[u] = ((cx[u]%MOD) + (cx[u-1]%MOD))%MOD;	
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    ans = ((ans%MOD) + (cx[i]%MOD))%MOD;
	std::cout<<ans<<"\n";
	return 0;
}
