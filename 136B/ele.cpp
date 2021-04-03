#include <bits/stdc++.h>
#define CHOR 100100

int cnt[CHOR],arr[CHOR],ans[CHOR];
int Z,c_a;

struct sq
{
	int l,r,id;
}Q[CHOR];

inline bool mo_comp(sq a, sq b)
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
				if(x < CHOR)
				{
					cnt[x]++;
					if(cnt[x] == x)
					c_a++;
					else if(cnt[x] == x+1)
					c_a--;	
				}	
				return;
			}

			void remove(int x)
			{
				if(x < CHOR)
				{
					cnt[x]--;
					if(cnt[x] == x)
					c_a++;
					else if(cnt[x] == x-1)
					c_a--;	
				}	
				return;
			}
};

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	mo T;
	Z = floor(sqrt(n));
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=0;i<m;i++)
	{
		std::cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
	}	
	std::sort(Q,Q+m,mo_comp);
	int mo_l = 0; 
	int mo_r = -1;
	c_a = 0;
	for(int i=0;i<m;i++)
	{
		int l = Q[i].l-1;
		int r = Q[i].r-1;
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
		ans[Q[i].id] = c_a;
	}	
	for(int i=0;i<m;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}