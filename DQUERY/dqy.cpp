#include <bits/stdc++.h>
#define CHOR 1000001

int cnt[CHOR];
int Z;
int arr[300001], ans[200001], ct;

struct sq
{
	int l,r,id;
}Q[200001];

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
				cnt[x]++;
				if(cnt[x] == 1)
				ct++;
				return;	
			}

			void remove(int x)
			{
				cnt[x]--;
				if(!cnt[x])
				ct--;
				return;	
			}
};

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	Z = (int)floor(sqrt(n));
	mo T;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	int q;
	std::cin>>q;
	ct = 0;
	for(int i=0;i<q;i++)
	{
		std::cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
	}	
	std::sort(Q,Q+q,mo_cmp);
	int mo_l = 1;
	int mo_r = 0;
	for(int i=0;i<q;i++)
	{
		int l = Q[i].l;
		int r = Q[i].r;
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
		ans[Q[i].id] = ct;
	}	
	for(int i=0;i<q;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}