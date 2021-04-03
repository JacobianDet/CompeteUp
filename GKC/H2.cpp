#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	freopen("H2.in", "r", stdin);
	freopen("H2.txt", "w", stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		ll n;
		std::cin>>n;
		std::string s;
		std::cin>>s;
		ll ws = 0;
		if(n & 1)
		ws = (n>>1) + 1;
		else ws = (n>>1);
		ll p1 = 0, p2 = 0, wsm = 0;
		ll zs = 0;
		while(p2 < n)
		{
			if((p2 - p1) == ws)
			{
				wsm -= (ll)(s[p1] - '0');
				p1++;
			}	
			wsm += (ll)(s[p2] - '0');
			p2++;
			zs = std::max(wsm, zs);
		}	
		std::cout<<"Case #"<<t<<": "<<zs<<"\n";
	}	
	return 0;
}