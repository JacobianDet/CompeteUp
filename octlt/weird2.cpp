#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::map<int, int> ctx;
std::map<int, std::vector<int> > zx;

std::vector<int> merger(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> res;
	int n = (int)a.size();
	int m = (int)b.size();
	int i = 0, j = 0;
	while(i < n && j < m)
	{
		if(a[i] < b[j])
		{	
			res.pb(a[i]);
			i++;
		}	
		else
		{
	    	res.pb(b[j]);
	    	j++;
	    }		
	}
	while(i < n)
	{
		res.pb(a[i]);
		i++;
	}	
	while(j < m)
	{
		res.pb(b[j]);
		j++;
	}
	return res;
}

ll bs2(int val)
{
	std::map<int, std::vector<int> >::iterator it = zx.lower_bound(val);
	std::vector<int> vx = it->second;
	ll lo = 0;
	ll hi = (ll)vx.size() - 1;
	val = ctx[val];
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(vx[mid] <= val)
		lo = mid;
		else hi = mid - 1;	
	}
	if((lo <= hi) && (vx[lo] <= val))
	return lo + 1;
	else return 0;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			std::cin>>x;
			ctx[x]++;
		}	
		for(std::map<int, int>::iterator it=ctx.begin();it != ctx.end();it++)
		zx[it->second].pb(it->first);	
		ll ax = 0;
		std::map<int, std::vector<int> >::reverse_iterator prit;
		for(std::map<int, std::vector<int> >::reverse_iterator rit = zx.rbegin();rit != zx.rend();rit++)
		{
			if(rit == zx.rbegin())
			{
				prit = rit;
				continue;
			}	
			else 
			{
				rit->second = merger(rit->second, prit->second);
				prit = rit;
			}
		}	
		for(std::map<int, int>::iterator it = ctx.begin();it != ctx.end();it++)
		ax += bs2(it->first);
		std::cout<<ax<<"\n";
		zx.clear();
		ctx.clear();
	}
	return 0;
}