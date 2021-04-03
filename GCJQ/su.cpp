#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<ll> cx;

ll alien(ll d)
{
	ll lo = 0;
	ll hi = 0;
	ll rm=0;
	for(ll i=cx.size()-1;i>0;i--)
	{	
		ll rx = cx[i]-cx[i-1]-1;
		if(rx >= 0)
		{	
			rm += rx;
			hi += rm;
		}	
	}	
	//std::cout<<"x"<<hi<<"\n";
	while(lo < hi)
	{
		ll mid = lo + (hi-lo)/2;
		ll res=0,i=0,rs=0;
		for(i=cx.size()-1;i>0;i--)
		{
			ll rx = cx[i]-cx[i-1]-1;
			if(rx >= 0)
			{	
				if(rx + res + rs < mid)
				{	
					res += rx;
					rs += res;
				}	
				else break;
			}
		}	
		//std::cout<<"x"<<mid<<" "<<res<<" "<<rs<<" "<<i<<"\n";
		ll en = 0;
		for(ll j=i;j>0;j--)
		{
			ll rx = (cx[j]-cx[j-1])-1;
			//std::cout<<"x"<<rx<<"\n";
			if(rx >= 0)
			{	
				if((j == i) && (rx + res + rs >= mid))
				en += (rx+res-mid+rs)*(1<<(j-1)) + (mid-rs)*(1<<(j-2));
				else en += rx*(1<<(j-1));
			}	
			//std::cout<<"y"<<en<<"\n";
		}	
		//std::cout<<"a"<<en<<"\n";
		if(en > d)
		lo = mid+1;
		else hi = mid;	
	}
	return lo;
} 

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	for(ll t=1;t<=T;t++)
	{
		ll d;
		std::cin>>d;
		std::string s;
		std::cin>>s;
		cx.pb(-1);
		for(ll i=0,j=(ll)s.size();i<j;i++)
		{
			if(s[i] == 'C')
			cx.pb(i);	
		}	
		cx.pb((ll)s.size());
		/*for(ll i=0,j=(ll)cx.size();i<j;i++)
		std::cout<<cx[i]<<" ";
		std::cout<<"\n";*/	
		if((ll)s.size()-(ll)cx.size()+2 > d)
		{	
			cx.clear();
			std::cout<<"Case #"<<t<<": "<<"IMPOSSIBLE\n";
			continue;
		}
		ll ans = alien(d);	
		std::cout<<"Case #"<<t<<": "<<ans<<"\n";
		cx.clear();	
	}	
	return 0;
}