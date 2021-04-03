#include <bits/stdc++.h>

typedef long long ll;

struct luz
{
	ll p,c,ind;
}req[100001];

ll ans[100001];

bool cmp(luz a, luz b)
{
	return (a.p < b.p);
}

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	{	
		std::cin>>req[i].p;
		req[i].ind = i;
	}	
	for(int i=0;i<n;i++)
	std::cin>>req[i].c;
	std::sort(req, req+n, cmp);
	std::multiset<ll, std::greater<ll> > Z;
	for(int i=0;i<n;i++)
	{
		ans[req[i].ind] += req[i].c;
		if(i > 0)
		Z.insert(req[i-1].c);
		int ctr = 0;
		for(std::multiset<ll, std::greater<ll> >::iterator it = Z.begin();it != Z.end();it++)
		{
			ctr++;
			if(ctr > k)
			break;
			ans[req[i].ind] += (*it);	
		}	
	}
	for(int i=0;i<n;i++)
	std::cout<<ans[i]<<" ";
	std::cout<<"\n";
	return 0;	
}