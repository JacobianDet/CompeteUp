#include <bits/stdc++.h>
#define MV (1<<20)

int seg[4*MV], arr[MV];

class segtree
{
	public: void build(int i, int s, int d);
			int merger1(int left, int right);
			int merger2(int left, int right);
			void update(int i, int s, int d, int x, int y);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = arr[s];
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	int lx = 0;
	for(lx=1;(1<<lx)<=(d-s+1);lx++);
	lx--;
	if(lx & 1)
	seg[i] = merger1(seg[2*i], seg[2*i+1]);
	else seg[i] = merger2(seg[2*i], seg[2*i+1]);
	return;	
}

int segtree::merger1(int left, int right)
{
	return (left | right);
}

int segtree::merger2(int left, int right)
{
	return (left ^ right);
}

void segtree::update(int i, int s, int d, int x, int y)
{
	if(s == d)
	{
		seg[i] = y;
		return;
	}	
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, y);
	else update(2*i+1, m+1, d, x, y);
	int lx = 0;
	for(lx=1;(1<<lx)<=(d-s+1);lx++);
	lx--;
	if(lx & 1)
	seg[i] = merger1(seg[2*i], seg[2*i+1]);
	else seg[i] = merger2(seg[2*i], seg[2*i+1]);
	return;		
}

int main(void)
{
	int n, q;
	std::cin>>n>>q;
	for(int i=1;i<=(1<<n);i++)
	std::cin>>arr[i];
	segtree T;
	T.build(1, 1, (1<<n));
	while(q--)
	{
		int x,y;
		std::cin>>x>>y;
		T.update(1, 1, (1<<n), x, y);
		std::cout<<seg[1]<<"\n";
	}	
	return 0;
}