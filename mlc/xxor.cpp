#include <bits/stdc++.h>
#define CHOR 100100

int cnt[31],ans[CHOR],arr[CHOR];
int Z;

struct sq
{
	int l,r,id;
}Q[CHOR];

inline bool mo_cmp(sq a, sq b)
{
	int b1 = a.l/Z;
	int b2 = b.l/Z;
	if(b1 != b2)
	return (b1 < b2);
	else return (a.r < b.r);	
}

class mo
{
	public: void add(int x)
			{
				for(int i=30;i>=0;i--)
				{
					if(x & (1 << i))
					cnt[i]++;	
				}	
				return;
			}

			void remove(int x)
			{
				for(int i=30;i>=0;i--)
				{
					if(x & (1 << i))
					cnt[i]--;	
				}	
				return;
			}
};

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	Z = floor(sqrt(n));
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=0;i<q;i++)
	{
		std::cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
	}	
	std::sort(Q,Q+q,mo_cmp);
	mo T;
	int mo_l = 0, mo_r = -1;
	for(int i=0;i<q;i++)
	{
		int l = Q[i].l - 1;
		int r = Q[i].r - 1;
		int sz = r-l+1;
		while(mo_r < r)
		{
			mo_r++;
			T.add(arr[mo_r]);
		}	
		while(mo_r > r)
		{
			T.remove(arr[mo_r]);
			mo_r--;
		}	
		while(mo_l < l)
		{
			T.remove(arr[mo_l]);
			mo_l++;
		}	
		while(mo_l > l)
		{
			mo_l--;
			T.add(arr[mo_l]);
		}	
		int az = 0;
		for(int j=30;j>=0;j--)
		{
			if(sz - cnt[j] > cnt[j])
			az |= (1 << j);
		}	
		ans[Q[i].id] = az;
	}	
	for(int i=0;i<q;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}