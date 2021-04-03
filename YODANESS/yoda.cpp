#include <bits/stdc++.h>
#define CHOR 30001
#define pb push_back

std::map<std::string, int> msi;
int ord[CHOR];

struct zex
{
	std::vector<int> tlna;
	int inc;
}seg[4*CHOR];

int bs1(int val, std::vector<int>& elec)
{
	int lo = 0;
	int hi = (int)elec.size()-1;
	while(lo < hi)
	{
		int mid = lo + (hi -lo)/2;
		if(ord[elec[mid]] < val)
		lo = mid + 1;
		else hi = mid;	
	}
	if(ord[elec[lo]] > val)	
	return lo;
	else return lo + 1;
}

class segtree
{
	public: void build(int i, int s, int d);
			zex merger(zex left, zex right);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].tlna.clear();
		seg[i].tlna.pb(s);
		seg[i].inc = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

zex segtree::merger(zex left, zex right)
{
	zex res;
	res.inc = 0;
	res.tlna.clear();
	for(int i=0,j=(int)left.tlna.size();i<j;i++)	
	res.inc += bs1(ord[left.tlna[i]], right.tlna);
	res.inc += (left.inc + right.inc);
	int i=0, j=0;
	int n1 = left.tlna.size(), n2 = right.tlna.size();
	while(i != n1 && j != n2)
	{
		if(ord[left.tlna[i]] < ord[right.tlna[j]])
		{
			res.tlna.pb(left.tlna[i]);
			i++;
		}	
		else if(ord[left.tlna[i]] > ord[right.tlna[j]])
		{
			res.tlna.pb(right.tlna[j]);
			j++;
		}	
	}
	while(i != n1)
	{
		res.tlna.pb(left.tlna[i]);
		i++;
	}	
	while(j != n2)
	{
		res.tlna.pb(right.tlna[j]);
		j++;	
	}	
	return res;
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
		msi.clear();
		int n;
		std::cin>>n;
		std::string s;
		for(int i=1;i<=n;i++)
		{
			std::cin>>s;
			msi[s] = i;
		}	
		for(int i=1;i<=n;i++)
		{
			std::cin>>s;
			ord[msi[s]] = i;
		}
		segtree D;
		D.build(1, 1, n);
		std::cout<<seg[1].inc<<"\n";	
	}	
	return 0;
}