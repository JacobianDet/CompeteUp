#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

ll c[100001], a[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	for(int i=0;i<n;i++)
	std::cin>>c[i];	
	std::set<std::pair<ll, int> > Z;
	for(int i=0;i<n;i++)
	Z.insert(mp(c[i], i));
	for(int i=0;i<m;i++)
	{
		ll cst = 0, rq = 0;
		int id = 0;
		std::cin>>id>>rq;
		id--;
		if(a[id] >= rq)
		{
			a[id] -= rq;
			cst += rq * c[id];
			if(!a[id])
			Z.erase(mp(c[id], id));	
			rq = 0;
		}	
		else
		{
			cst += a[id] * c[id];
			rq -= a[id];
			a[id] = 0;
			Z.erase(mp(c[id], id));
			while(!Z.empty() && rq)
			{
				std::pair<ll, int> px = *Z.begin();
				int ix = px.second;
				if(a[ix] >= rq)
				{
					a[ix] -= rq;
					cst += rq * c[ix];
					if(!a[ix])
					Z.erase(Z.begin());	
					rq = 0;

				}
				else
				{
					cst += a[ix] * c[ix];
					rq -= a[ix];
					a[ix] = 0;
					Z.erase(Z.begin());
				}
			}
			if(rq)
			cst = 0;
		}
		std::cout<<cst<<"\n";
	}	
	return 0;
}