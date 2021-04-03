#include <bits/stdc++.h>
#define CHOR1 1<<20
#define CHOR2 100001

typedef long long ll;

int cnt[CHOR1],arr[CHOR2];
int Z,k;
ll c_p,ans[CHOR2];

struct sq
{
	int l,r,id;
}Q[CHOR2];

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
				c_p += 1LL * cnt[x ^ k];
				cnt[x]++;
			}

			void remove(int x)
			{
				cnt[x]--;
				c_p -= 1LL * cnt[x ^ k];
			}
};

int main(void)
{
	int n,m;
	std::cin>>n>>m>>k;
	c_p = 0;
	Z = floor(sqrt(n));
	for(int i=1;i<=n;i++)
	{
		int t;
		std::cin>>t;
		arr[i] = arr[i-1] ^ t;
	}
	mo T;	
	for(int i=0;i<m;i++)
	{
		std::cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
	}	
	std::sort(Q,Q+m,mo_cmp);
	int mo_l = 0, mo_r = -1;
	for(int i=0;i<m;i++)
	{
		int l = Q[i].l-1;
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
		ans[Q[i].id] = c_p;
	}	
	for(int i=0;i<m;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}