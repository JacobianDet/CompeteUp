#include <bits/stdc++.h>
#define CHOR 200200

typedef long long ll;

int cnt[1000001],arr[CHOR];
int Z;
ll can,ans[CHOR];

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
				can -= 1LL*cnt[x]*cnt[x]*x;
				cnt[x]++;
				can += 1LL*cnt[x]*cnt[x]*x;
				return;
			}

			void remove(int x)
			{
				can -= 1LL*cnt[x]*cnt[x]*x;
				cnt[x]--;
				can += 1LL*cnt[x]*cnt[x]*x;
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
	Z = (int)floor(sqrt(n));
	mo T;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	can = 0;
	for(int i=0;i<q;i++)
	{
		std::cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
	}	
	std::sort(Q,Q+q,mo_cmp);
	int mo_l = 0;
	int mo_r = -1;
	for(int i=0;i<q;i++)
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
		ans[Q[i].id] = can;
	}	
	for(int i=0;i<q;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}