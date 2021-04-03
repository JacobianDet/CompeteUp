#include <bits/stdc++.h>
#define MV 100001
#define LMV 20

int arr[MV];
int SB[MV][LMV];

int bs1a(int val, int n)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(val < arr[mid])
		hi = mid;
		else lo = mid + 1;	
	}	
	if(val >= arr[lo])
	return lo;
	else if(lo == 1)
	return -1;
	else return lo - 1;	
}

class ST
{
	public: void build(int n);
			int query(int qs, int qd); 
};

void ST::build(int n)
{
	for(int i=1;i<n;i++)
	SB[i][0] = arr[i+1] - arr[i];
	for(int j=1;(1<<j)<n;j++)
	{
		for(int i=1;i<n;i++)
		{	
			if(i + (1<<(j-1)) < n)
			SB[i][j] = std::max(SB[i][j-1], SB[i+(1<<(j-1))][j-1]);
		}		
	}	
	return;
}

int ST::query(int qs, int qd)
{
	int lx = 0;
	for(lx=0;(1<<lx)<=(qd-qs+1);lx++);
	lx--;	
	int mx = std::max(SB[qs][lx], SB[qd-(1<<lx)+1][lx]);
	return mx;	
}

int bs1b(int r, int val, ST &Z)
{
	int lo = 1;
	int hi = r - 1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(Z.query(mid, r - 1) <= val)
		hi = mid;
		else lo = mid + 1;	
	}	
	if(Z.query(lo, r - 1) > val)
	return r;	
	else return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	std::cin>>q;
	if(n == 1)
	{
		while(q--)
		{
			int t,d;
			std::cin>>t>>d;
			if(arr[1] <= t)
			std::cout<<"1\n";
			else std::cout<<"0\n";	
		}	
	}
	else
	{
		ST Z;
		Z.build(n);
		while(q--)
		{
			int t,d;
			std::cin>>t>>d;
			int r = bs1a(t, n);
			if(r == -1)
			std::cout<<"0\n";
			else
			{
				if(r == 1)
				std::cout<<"1\n";
				else
				{
					int ans = bs1b(r, d, Z);
					std::cout<<ans<<"\n";
				}	
			}	
		}
	}
	return 0;	
}