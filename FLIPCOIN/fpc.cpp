#include <bits/stdc++.h>
#define MV 100001

int Z;

struct invx
{
	int ctr[2];
}SQ[350];

int arr[MV], lazy[350];

class sqdec
{
	public: void build(int n);
			void update(int l, int r, int n);
			int query(int l, int r, int n);
};

void sqdec::build(int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i] = 0;
		int b = i/Z;
		SQ[b].ctr[arr[i]]++;
	}
	return;	
}

void sqdec::update(int l, int r, int n)
{
	int c_l = l/Z;
	int c_r = r/Z;
	if(c_l == c_r)
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			arr[i] ^= 1;
			lazy[c_l] = 0;	
		}
		for(int i=l;i<=r;i++)
		{	
			SQ[c_l].ctr[arr[i]]--;
			arr[i] ^= 1;	
			SQ[c_l].ctr[arr[i]]++;
		}	
	}	
	else
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			arr[i] ^= 1;
			lazy[c_l] = 0;	
		}
		if(lazy[c_r])
		{
			for(int i=c_r*Z,j=std::min(n-1, (c_r+1)*Z);i<j;i++)
			arr[i] ^= 1;
			lazy[c_r] = 0;	
		}	
		for(int i=l,j=(c_l+1)*Z;i<j;i++)
		{
			SQ[c_l].ctr[arr[i]]--;
			arr[i] ^= 1;
			SQ[c_l].ctr[arr[i]]++;
		}	
		for(int i=(c_l+1);i<c_r;i++)
		{
			int tmp = SQ[i].ctr[0];
			SQ[i].ctr[0] = SQ[i].ctr[1];
			SQ[i].ctr[1] = tmp;
			lazy[i] = (lazy[i] + 1)%2;
		}	
		for(int i=c_r*Z;i<=r;i++)
		{
			SQ[c_r].ctr[arr[i]]--;
			arr[i] ^= 1;
			SQ[c_r].ctr[arr[i]]++;
		}	
	}
	return;	
}

int sqdec::query(int l, int r, int n)
{
	int c_l = l/Z;
	int c_r = r/Z;
	int hs = 0;
	if(c_l == c_r)
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			arr[i] ^= 1;
			lazy[c_l] = 0;	
		}
		for(int i=l;i<=r;i++)
		{	
			if(arr[i])
			hs++;	
		}	
	}	
	else
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			arr[i] ^= 1;
			lazy[c_l] = 0;	
		}
		if(lazy[c_r])
		{
			for(int i=c_r*Z,j=std::min(n-1, (c_r+1)*Z);i<j;i++)
			arr[i] ^= 1;
			lazy[c_r] = 0;	
		}	
		for(int i=l,j=(c_l+1)*Z;i<j;i++)
		{
			if(arr[i])
			hs++;	
		}	
		for(int i=(c_l+1);i<c_r;i++)
		hs += SQ[i].ctr[1];
		for(int i=c_r*Z;i<=r;i++)
		{
			if(arr[i])
			hs++;	
		}	
	}
	return hs;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	Z = floor(sqrt(n));
	sqdec T;
	T.build(n);
	while(q--)
	{
		int x,l,r;
		std::cin>>x>>l>>r;
		if(x)
		std::cout<<T.query(l, r, n)<<"\n";
		else T.update(l, r, n);
	}	
	return 0;
}