#include <bits/stdc++.h>
#define pb push_back
#define pof pop_front

typedef long long ll;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,k;
		std::cin>>n>>k;
		std::string s;
		std::cin>>s;
		std::deque<int> D;
		int cv = 0;
		for(int i=0;i<k-1;i++)
		{
			D.pb(i);
			if(s[i] != s[i+1])
			cv++;	
		}	
		D.pb(k-1);
		ll ans = 0;
		for(int i=1;i<n-k+1;i++)
		{	
			if(s[i+k-1] != s[D.back()])
			cv++;
			ans += 1LL*cv;
			if(s[i] != s[D.front()])
			cv--;
			D.pof();
			D.pb(i+k-1);
		}
		std::cout<<ans<<"\n";	
	}
	return 0;
}