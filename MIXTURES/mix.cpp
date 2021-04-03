#include <bits/stdc++.h>
#define mp std::make_pair
#define CHOR 1e18
typedef long long ll;

ll mix[100];
std::pair<ll, ll> memo[100][100];

std::pair<ll, ll> hp(ll i, ll j)
{
	if(i == j)
	return mp(0, mix[i]);
	else if((j-i) == 1)
	return mp(mix[i]*mix[j], (mix[i] + mix[j])%100);
	if(memo[i][j] != mp((ll)-1, (ll)-1))
	return memo[i][j];	
	ll ans = CHOR;
	ll ne = 0;
	for(ll k=i;k<j;k++)
	{
		ll ansp = ans;
		std::pair<ll, ll> m1 = hp(i, k);
		std::pair<ll, ll> m2 = hp(k+1, j);
		ans = std::min((ll)ans, (ll)(m1.first + m2.first + (m1.second)*(m2.second)));
		if(ansp != ans)
		ne = (m1.second + m2.second)%100;
	}
	memo[i][j] = mp(ans, ne);	
	return memo[i][j];
}

int main(void)
{
	ll n;
	while(std::cin>>n)
	{
		for(ll i=0;i<100;i++)
		{
			for(ll j=0;j<100;j++)
			memo[i][j] = mp((ll)-1, (ll)-1);	
		}	
		for(ll i=0;i<n;i++)
		std::cin>>mix[i];
		ll ans = hp(0, n-1).first;
		std::cout<<ans<<"\n";
	}	
	return 0;
}