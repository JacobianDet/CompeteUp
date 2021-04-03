#include <bits/stdc++.h>
#define pb push_back

typedef std::vector<int> vi;
typedef std::map<int, int> mii;

struct sb
{
	int s,b;
};

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,q;
		std::cin>>n>>q;
		vi arr;
		mii mx;
		for(int i=0;i<n;i++)
		{
			int t;
			std::cin>>t;
			arr.pb(t);
			mx[t] = i+1;
		}	
		vi quy;
		for(int i=0;i<q;i++)
		{
			int t;
			std::cin>>t;
			quy.pb(t);
		}	
		vi arr2(arr.begin(), arr.end());
		std::sort(arr2.begin(), arr2.end());
		sb zex[n];
		for(int i=0;i<n;i++)
		{
			zex[mx[arr2[i]]-1].s = i;
			zex[mx[arr2[i]]-1].b = n-i-1;
		}
		for(int i=0;i<q;i++)
		{
			int ctr = 0;
			int lo = 1;
			int hi = n;
			while(lo <= hi)
			{
				int mid = lo + (hi - lo)/2;
				if(arr[mid-1] == quy[i])
				break;
				else if(arr[mid-1] > quy[i])
				{
					if(mid > mx[quy[i]])
					hi = mid - 1;
					else if(mid < mx[quy[i]])
					{
						ctr++;
						zex[mx[quy[i]]-1].s--;
						zex[mx[quy[i]]-1].b--;
						lo = mid + 1;
					}	
				}	
				else
				{
					if(mid < mx[quy[i]])
					lo = mid + 1;
					else if(mid > mx[quy[i]])
					{
						ctr++;
						zex[mx[quy[i]]-1].s--;
						zex[mx[quy[i]]-1].b--;
						hi = mid - 1;
					}	
				}	
			}
			if((zex[mx[quy[i]]-1].s < 0) || (zex[mx[quy[i]]-1].b < 0))
			ctr = -1;
			std::cout<<ctr<<"\n";	
		}	
	}
	return 0;	
}