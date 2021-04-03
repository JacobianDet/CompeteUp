#include <bits/stdc++.h>
#define pb push_back
#define MV 1000001

typedef long long ll;

int arr[MV];

struct sonu
{
	std::vector<int> vx;
	ll ct;
}seg[4*MV];

ll bs1(int v, std::vector<int>& elec)
{
	ll lo = 0;
	ll hi = (ll)elec.size() - 1;
	while(lo < hi)
	{
		ll mid = lo + (hi-lo)/2;
		if(elec[mid] < v)
		lo = mid + 1;
		else hi = mid;	
	}	
	if(elec[lo] >= v)
	return lo;
	else return lo + 1;
}

class segtree
{
	public: void build(int i, int s, int d);
			sonu merger(sonu left, sonu right);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].vx.clear();
		seg[i].vx.pb(arr[s]);
		seg[i].ct = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

sonu segtree::merger(sonu left, sonu right)
{
	sonu res;
	res.ct = 0;
	for(int i=0,j=(int)left.vx.size();i<j;i++)
	res.ct += bs1(left.vx[i], right.vx);
	res.ct += (left.ct + right.ct);
	int n1 = (int)left.vx.size(), n2 = (int)right.vx.size();
	int i = 0, j = 0;
	while(i != n1 && j != n2)
	{
		if(left.vx[i] < right.vx[j])
		{
			res.vx.pb(left.vx[i]);
			i++;
		}	
		else 
		{
			res.vx.pb(right.vx[j]);
			j++;
		}	
	}
	while(i != n1)
	{
		res.vx.pb(left.vx[i]);
		i++;
	}	
	while(j != n2)
	{
		res.vx.pb(right.vx[j]);
		j++;
	}	
	return res;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	segtree T;
	T.build(1, 1, n);
	ll ctx = seg[1].ct;
	if(n & 1)
	{
		if(ctx & 1)
		std::cout<<"Petr\n";
		else std::cout<<"Um_nik\n";	
	}	
	else
	{
		if(ctx & 1)
		std::cout<<"Um_nik\n";
		else std::cout<<"Petr\n";	
	}	
	return 0;
}