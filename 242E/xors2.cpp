#include <bits/stdc++.h>
#define MV 100001

typedef long long ll;

int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int Z, lazy[350];

struct sqx
{
	int ctr[21];
}SQ[350];

int arr[MV];

class sqdec
{
	public: void build(int n);
			void update(int l, int r, int n, int x);
			ll query(int l, int r, int n);
};

void sqdec::build(int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i] = readInt();
		int b = i/Z;
		for(int j=0;j<21;j++)
		{
			if(arr[i] & (1<<j))
			SQ[b].ctr[j]++;	
		}
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
			arr[i] ^= lazy[c_l];
			lazy[c_l] = 0;
		}	
		for(int i=l;i<=r;i++)
		{
			for(int j=0;j<21;j++)
			{
				if(arr[i] & (1<<j))
				SQ[c_l].ctr[j]--;
				if((arr[i] ^ x) & (1<<j))
				SQ[c_l].ctr[j]++;	
			}	
			arr[i] ^= x;	
		}	
	}
	else
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			arr[i] ^= lazy[c_l];
			lazy[c_l] = 0;
		}	
		if(lazy[c_r])
		{
			for(int i=c_r*Z,j=std::min(n-1, (c_r+1)*Z);i<j;i++)
			arr[i] ^= lazy[c_r];
			lazy[c_r] = 0;	
		}	
		for(int i=l,k=std::min(n-1, (c_l+1)*Z);i<k;i++)
		{
			for(int j=0;j<21;j++)
			{
				if(arr[i] & (1<<j))
				SQ[c_l].ctr[j]--;
				if((arr[i] ^ x) & (1<<j))
				SQ[c_l].ctr[j]++;		
			}	
			arr[i] ^= x;	
		}
		for(int i=c_l+1;i<c_r;i++)
		{
			for(int j=0;j<21;j++)
			{
				if(x & (1<<j))
				SQ[i].ctr[j] = Z - SQ[i].ctr[j];	
			}
			lazy[i] ^= x;	
		}	
		for(int i=c_r*Z;i<=r;i++)
		{
			for(int j=0;j<21;j++)
			{
				if(arr[i] & (1<<j))
				SQ[c_r].ctr[j]--;
				if((arr[i] ^ x) & (1<<j))
				SQ[c_r].ctr[j]++;	
			}	
			arr[i] ^= x;	
		}	
	}
	return;	
}

ll sqdec::query(int l, int r, int n)
{
	ll sum = 0;
	int c_l = l/Z;
	int c_r = r/Z;
	if(c_l == c_r)
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			arr[i] ^= lazy[c_l];
			lazy[c_l] = 0;
		}	
		for(int i=l;i<=r;i++)
		sum += 1LL*arr[i];
	}
	else
	{
		if(lazy[c_l])
		{
			for(int i=c_l*Z,j=std::min(n-1, (c_l+1)*Z);i<j;i++)
			arr[i] ^= lazy[c_l];
			lazy[c_l] = 0;
		}	
		if(lazy[c_r])
		{
			for(int i=c_r*Z,j=std::min(n-1, (c_r+1)*Z);i<j;i++)
			arr[i] ^= lazy[c_r];
			lazy[c_r] = 0;	
		}	
		for(int i=l,k=std::min(n-1, (c_l+1)*Z);i<k;i++)
		sum += 1LL*arr[i];
		for(int i=c_l+1;i<c_r;i++)
		{
			for(int j=0;j<21;j++)
			{
				if(SQ[i].ctr[j])
				sum += SQ[i].ctr[j]*(1LL<<j);		
			}	
		}	
		for(int i=c_r*Z;i<=r;i++)
		sum += 1LL*arr[i];
	}
	return sum;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	int n = readInt();
	Z = floor(sqrt(n));
	sqdec T;
	T.build(n);
	int q = readInt();
	while(q--)
	{
		int x = readInt();
		if(x == 1)
		{
			int l = readInt();
			int r = readInt();
			l--;
			r--;
			std::cout<<T.query(l, r, n)<<"\n";
		}	
		else
		{
			int l = readInt();
			int r = readInt();
			int k = readInt();
			l--;
			r--;
			T.update(l, r, n, k);
		}	
	}	
	return 0;
}
