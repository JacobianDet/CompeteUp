#include <bits/stdc++.h>
#define MV 100001

int Z;
int arr[MV], p[MV], lazy[350];

struct ctx
{
	int ctr[1000001];
}SQ[350];

class sqdec
{
	public: void build(int n);
			void update(int l, int r, int n, int x);
			int query(int l, int r, int n, int x);
};

void sqdec::build(int n)
{
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
		p[i] = arr[i];
		if(i)
		p[i] ^= p[i-1];	
		int b = i/Z;
		SQ[b].ctr[p[i]]++;
	}
	return;	
}

void sqdec::update(int l, int r, int n, int x)
{
	int c_l = l/Z;
	int c_r = r/Z;
	if(c_l == c_r)
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			{
				SQ[c_l].ctr[p[i]]--;
				p[i] ^= lazy[c_l];
				SQ[c_l].ctr[p[i]]++; 
			}	
			lazy[c_l] = 0;
		}
		for(int i=l;i<=r;i++)
		{
			SQ[c_l].ctr[p[i]]--;
			p[i] ^= x;
			SQ[c_l].ctr[p[i]]++;
		}	
	}
	else
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			{
				SQ[c_l].ctr[p[i]]--;
				p[i] ^= lazy[c_l];
				SQ[c_l].ctr[p[i]]++;
			}	
			lazy[c_l] = 0;
		}	
		if(lazy[c_r])
		{
			for(int i=c_r*Z,j=std::min(n-1, (c_r+1)*Z);i<j;i++)
			{
				SQ[c_r].ctr[p[i]]--;
				p[i] ^= lazy[c_r];
				SQ[c_r].ctr[p[i]]++;
			}
			lazy[c_r] = 0;	
		}	
		for(int i=l,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
		{
			SQ[c_l].ctr[p[i]]--;
			p[i] ^= x;
			SQ[c_l].ctr[p[i]]++;
		}	
		for(int i=c_l+1;i<c_r;i++)
		lazy[i] ^= x;
		for(int i=c_r*Z;i<=r;i++)
		{
			SQ[c_r].ctr[p[i]]--;
			p[i] ^= x;
			SQ[c_r].ctr[p[i]]++;
		}	
	}
	return;	
}

int sqdec::query(int l, int r, int n, int x)
{
	int xs = 0;
	int c_l = l/Z;
	int c_r = r/Z;
	if(c_l == c_r)
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			{
				SQ[c_l].ctr[p[i]]--;
				p[i] ^= lazy[c_l];
				SQ[c_l].ctr[p[i]]++; 
			}	
			lazy[c_l] = 0;
		}
		for(int i=l;i<=r;i++)
		{
			if(p[i] == x)
			xs++;	
		}	
	}
	else
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			{
				SQ[c_l].ctr[p[i]]--;
				p[i] ^= lazy[c_l];
				SQ[c_l].ctr[p[i]]++;
			}	
			lazy[c_l] = 0;
		}	
		if(lazy[c_r])
		{
			for(int i=c_r*Z,j=std::min(n-1, (c_r+1)*Z);i<j;i++)
			{
				SQ[c_r].ctr[p[i]]--;
				p[i] ^= lazy[c_r];
				SQ[c_r].ctr[p[i]]++;
			}
			lazy[c_r] = 0;	
		}	
		for(int i=l,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
		{
			if(p[i] == x)
			xs++;	
		}	
		for(int i=c_l+1;i<c_r;i++)
		xs += SQ[i].ctr[x ^ lazy[i]];
		for(int i=c_r*Z;i<=r;i++)
		{
			if(p[i] == x)
			xs++;	
		}	
	}
	return xs;	
}

int main(void)
{
	int n,q;
	std::cin>>n>>q;
	Z = floor(sqrt(n));
	sqdec T;
	T.build(n);
	while(q--)
	{
		int x,l,k;
		std::cin>>x>>l>>k;
		l--; 
		if(--x)
		std::cout<<T.query(0, l, n, k)<<"\n";
		else
		{
			int c = arr[l] ^ k;
			arr[l] = k;
			T.update(l, n-1, n, c);
		}	
	}	
	return 0;
}