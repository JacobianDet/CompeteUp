#include <bits/stdc++.h>
#define mp std::make_pair
#define MV 100001

struct vfx
{
	std::pair<int, int> mv;
	std::pair<int, int> lb;
	std::pair<int, int> rb;
}seg[4*MV];

int arr[MV];

class segtree
{
	public: void build(int i, int s, int d);
			vfx merger(vfx left, vfx right);
			vfx query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].mv = mp(arr[s], 1);
		seg[i].lb = mp(arr[s], 1);
		seg[i].rb = mp(arr[s], 1);
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

vfx segtree::merger(vfx left, vfx right)
{
	vfx res;
	if(left.lb.first == right.lb.first)
	res.lb = mp(left.lb.first, left.lb.second + right.lb.second);
	else res.lb = left.lb;	
	if(right.rb.first == left.rb.first)
	res.rb = mp(right.rb.first, left.rb.second + right.rb.second);
	else res.rb = right.rb;
	if(left.rb.first == right.lb.first)
	{	
		res.mv.second = std::max(std::max(left.rb.second + right.lb.second, std::max(res.lb.second, res.rb.second)), std::max(left.mv.second, right.mv.second));
		if(res.mv.second == left.rb.second + right.lb.second)
		res.mv.first = left.rb.first;
		else if(res.mv.second == left.mv.second)
		res.mv.first = left.mv.first;
		else if(res.mv.second == right.mv.second)
		res.mv.first = right.mv.first;
		else if(res.mv.second == res.lb.second)
		res.mv.first = res.lb.first;
		else res.mv.first = res.rb.first;	
	}
	else
	{
		res.mv.second = std::max(left.mv.second, std::max(right.mv.second, std::max(res.lb.second, res.rb.second)));
		if(res.mv.second == left.mv.second)
		res.mv.first = left.mv.first;
		else if(res.mv.second == right.mv.second)
		res.mv.first = right.mv.first;
		else if(res.mv.second == res.lb.second)
		res.mv.first = res.lb.first;
		else res.mv.first = res.rb.first;	
	}	
	return res;		
}

vfx segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return {{0, 0}, {0, 0}, {0, 0}};
	if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	vfx left = query(2*i, s, m, qs, qd);
	vfx right = query(2*i+1, m+1, d, qs, qd);
	return merger(left, right);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n;
	while(n)
	{
		std::cin>>q;
		for(int i=1;i<=n;i++)
		std::cin>>arr[i];
		segtree T;
		T.build(1, 1, n);
		/*for(int i=1;i<4*n;i++)
		std::cout<<seg[i].lb.first<<" "<<seg[i].lb.second<<" "<<seg[i].rb.first<<" "<<seg[i].rb.second<<" "<<seg[i].mv.first<<" "<<seg[i].mv.second<<"\n";*/	
		while(q--)
		{
			int l,r;
			std::cin>>l>>r;
			std::cout<<T.query(1, 1, n, l, r).mv.second<<"\n";
		}
		std::cin>>n;	
	}	
	return 0;
}