#include <bits/stdc++.h>
#define MV 100001

int arr[MV];

struct zx
{
	int loct, poct, soct, toct, lect, pect, sect, tect;
}seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			zx merger(zx left, zx right);
			void update(int i, int s, int d, int x, int val);
			zx query(int i, int s, int d);
			void trav(int i, int s, int d);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		if(__builtin_popcount(arr[s]) & 1)
		{
			seg[i].loct = (d-s+1);
			seg[i].poct = (d-s+1);
			seg[i].soct = (d-s+1);
			seg[i].toct = (d-s+1);
			seg[i].lect = 0;
			seg[i].pect = 0;
			seg[i].sect = 0;
			seg[i].tect = 0;
		}	
		else
		{
			seg[i].lect = (d-s+1);
			seg[i].pect = (d-s+1);
			seg[i].sect = (d-s+1);
			seg[i].tect = (d-s+1);
			seg[i].loct = 0;
			seg[i].poct = 0;
			seg[i].soct = 0;
			seg[i].toct = 0;
		}
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

zx segtree::merger(zx left, zx right)
{
	zx res;
	int lf1 = 0, lf2 = 0, lf3 = 0, lf4 = 0, lf5 = 0, lf6 = 0, lf7 = 0, lf8 = 0, lf9 = 0, lf10 = 0, lf11 = 0, lf12 = 0;
	if(left.tect && right.poct)
	lf1 = left.tect + right.poct;
	if(right.tect && left.soct)
	lf2 = right.tect + left.soct;
	if(left.toct && right.poct)
	lf3 = left.toct + right.poct;
	if(right.toct && left.soct)
	lf4 = right.toct + left.soct;
	if(left.toct)
	lf5 = left.toct + right.pect;
	if(right.toct)
	lf6 = right.toct + left.sect;
	if(left.tect)
	lf7 = left.tect + right.pect;
	if(right.tect)
	lf8 = right.tect + left.sect;
	if(left.sect && right.poct)
	lf9 = left.sect + right.poct;
	if(left.soct && right.pect)
	lf10 = left.soct + right.pect;
	if(left.soct && right.poct)
	lf11 = left.soct + right.poct;
	lf12 = left.sect + right.pect;
	res.poct = std::max(left.poct, std::max(lf1, lf5));
	res.soct = std::max(right.soct, std::max(lf2, lf6));  
	res.pect = std::max(left.pect, std::max(lf3, lf7));
	res.sect = std::max(right.sect, std::max(lf4, lf8));
	res.loct = std::max(right.loct, std::max(left.loct, std::max(res.poct, std::max(res.soct, std::max(lf9, lf10)))));
	res.lect = std::max(right.lect, std::max(left.lect, std::max(res.pect, std::max(res.sect, std::max(lf12, lf11)))));
	if(left.tect && right.tect)
	{
		res.tect = left.tect + right.tect;
		res.toct = 0;
	}
	else if(left.toct && right.toct)
	{
		res.tect = left.toct + right.toct;
		res.toct = 0;
	}	
	else if(left.tect && right.toct)
	{
		res.toct = left.tect + right.toct;
		res.tect = 0;
	}	
	else if(left.toct && right.tect)
	{
		res.toct = left.toct + right.tect;
		res.tect = 0;
	}
	res.loct = std::max(res.toct, res.loct);
	res.lect = std::max(res.tect, res.lect);
	return res;
}

void segtree::update(int i, int s, int d, int x, int val)
{
	if(s == d)
	{
		arr[s] = val;
		if(__builtin_popcount(arr[s]) & 1)
		{
			seg[i].loct = (d-s+1);
			seg[i].poct = (d-s+1);
			seg[i].soct = (d-s+1);
			seg[i].toct = (d-s+1);
			seg[i].lect = 0;
			seg[i].pect = 0;
			seg[i].sect = 0;
			seg[i].tect = 0;
		}	
		else
		{
			seg[i].lect = (d-s+1);
			seg[i].pect = (d-s+1);
			seg[i].sect = (d-s+1);
			seg[i].tect = (d-s+1);
			seg[i].loct = 0;
			seg[i].poct = 0;
			seg[i].soct = 0;
			seg[i].toct = 0;
		}
		return;
	}
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, val);
	else update(2*i+1, m+1, d, x, val);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

/*void segtree::trav(int i, int s, int d)
{
	std::cout<<s<<" "<<d<<" "<<seg[i].pect<<" "<<seg[i].sect<<" "<<seg[i].tect<<" "<<seg[i].lect<<" "<<seg[i].poct<<" "<<seg[i].soct<<" "<<seg[i].toct<<" "<<seg[i].loct<<"\n";
	if(s == d)
	return;
	int m = (s + d)/2;
	trav(2*i, s, m);
	trav(2*i+1, m+1, d);
	return;	
}*/

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(arr, 0, sizeof(arr));
		int n,q;
		std::cin>>n>>q;
		for(int i=1;i<=n;i++)
		std::cin>>arr[i];
		segtree Z;
		Z.build(1, 1, n);
		std::cout<<"Case #"<<t<<": ";
		while(q--)
		{
			int p,v;
			std::cin>>p>>v;
			p++;
			Z.update(1, 1, n, p, v);
			//Z.trav(1, 1, n);
			std::cout<<seg[1].lect<<" ";
		}	
		std::cout<<"\n";
	}
	return 0;
}