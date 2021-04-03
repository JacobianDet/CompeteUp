#include <bits/stdc++.h>
#define CHOR 50005

struct sfx
{
	int linb[CHOR];
	int bans[CHOR];
}block[250];

int arr1[2*CHOR], arr2[2*CHOR], next[2*CHOR], prev[2*CHOR], last[2*CHOR];
int Z,B,n;
int indx[2*CHOR], found[2*CHOR], te;

class LazyMap
{
	public: LazyMap()
			{
				memset(indx,0,sizeof(indx));
				memset(found,0,sizeof(found));
				te = 0;
			}
			void clear(void)
			{
				te++;
				return;
			}
			bool KF(int i)
			{
				return (found[i] == te);
			}
			void setter(int i, int val)
			{
				found[i] = te;
				indx[i] = val;
				return;
			}
			int getter(int i)
			{
				return indx[i];
			}
}axe;

class sqrtdec
{
	public: void build(void);
			int query(int l, int r);
};

void sqrtdec::build(void)
{
	for(int i=1;i<=n+1;i++)
	{	
		prev[i] =  0;
		next[i] = n+2;
	}	
	for(int i=1;i<=n+1;i++)
	{
		int j = last[arr2[i]];
		if(j)
		{
			next[j] = i;
			prev[i] = j;
		}	
		last[arr2[i]] = i;
	}	
	for(int b=1;b<=B;b++)
	{
		int l = b*Z - Z + 1;
		int r = std::min(b*Z, n+1);
		for(int i=l;i<=r;i++)
		{
			if(next[i] > r)
			{
				int x = i;
				while(x)
				{
					block[b].linb[x] = i;
					x = prev[x];
				}
			}	
		}	
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int b=2;b<=B;b++)
		{
			if(!block[b].linb[i])
			block[b].linb[i] = block[b-1].linb[i];	
		}	
	}
	int anx = 0;
	for(int b=1;b<=B;b++)
	{
		axe.clear();
		int c_l = b*Z - Z + 1;
		anx = 0;
		for(int i=c_l;i<=n+1;i++)
		{
			if(!axe.KF(arr2[i]))	
			axe.setter(arr2[i], i);
			anx = std::max(anx, i - indx[arr2[i]]);
			block[b].bans[i] = anx;
		}	
	}	
	return;
}

int sqrtdec::query(int l, int r)
{
	int b_l = (l + Z - 1)/Z;
	int b_r = r/Z;
	if(b_l >= b_r)
	{
		axe.clear();
		int anx = 0;
		for(int i=l;i<=r;i++)
		{
			if(!axe.KF(arr2[i]))
			axe.setter(arr2[i], i);
			anx = std::max(anx, i - indx[arr2[i]]);
		}	
		return anx;
	}	
	else
	{
		int e_l = b_l*Z;
		int anx = block[b_l+1].bans[r];
		for(int i=l;i<=e_l;i++)
		{
			if(prev[i] < l)
			{
				int y = block[r/Z].linb[i];
				while(next[y] <= r)
				y = next[y];
				anx = std::max(anx, y - i);	
			}	
		}
		return anx;	
	}	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(last, 0, sizeof(last));
	int q;
	std::cin>>n>>q;
	Z = floor(sqrt(n+1));
	B = ceil((double)(n+1)/Z);
	for(int i=1;i<=n;i++)
	{	
		std::cin>>arr1[i];
		arr2[i+1] = arr2[i] + arr1[i];
	}	
	for(int i=1;i<=n+1;i++)
	arr2[i] += CHOR;	
	sqrtdec T;
	T.build();
	for(int i=0;i<q;i++)
	{
		int l,r;
		std::cin>>l>>r;
		r++;
		std::cout<<T.query(l, r)<<"\n";
	}	
	return 0;
}