#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<ll> a1, a2;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		ll t;
		std::cin>>t;
		a1.pb(t);
		a2.pb(t);
	}	
	ll m1 = 0, m2 = 0, c1 = 0, c2 = 0;
	std::sort(a1.begin(), a1.end());
	std::sort(a2.rbegin(), a2.rend());
	for(int i=0;i<n;i++)
	{
		if(m1 + a1[i] - m1/10 > m1)
		{
			c1++;
			m1 = m1 + a1[i] - m1/10;
		}	
		if(m2 + a2[i] - m2/10 > m2)
		{
			c2++;
			m2 = m2 + a2[i] - m2/10;
		}
	}	
	if(m1 > m2)
	std::cout<<m1<<" "<<c1<<"\n";
	else if(m1 < m2)
	std::cout<<m2<<" "<<c2<<"\n";
	else std::cout<<m1<<" "<<std::min(c1, c2)<<"\n";
	return 0;	
}