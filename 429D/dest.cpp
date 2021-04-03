#include <bits/stdc++.h>
#define CHOR 300300

int cnt[CHOR],arr[CHOR],ans[CHOR];
int Z;
std::set<int> s;

struct sq
{
	int l,r,k,id;
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
	public: void add(int x, int y)
			{
				cnt[x]++;
				if(cnt[x] >= y)
				s.insert(x);
				return;
			}

			void remove(int x, int y)
			{
				bool f = 0;
				if(cnt[x] >= y)
				f = 1;
				cnt[x]--;
				if(f && cnt[x] < y)
				s.erase(x);
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
	mo T;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=0;i<q;i++)
	{	
		std::cin>>Q[i].l>>Q[i].r>>Q[i].k;
		Q[i].id = i;
	}
	std::sort(Q,Q+q,mo_cmp);
	int mo_l = 0;
	int mo_r = -1;
	for(int i=0;i<q;i++)
	{
		int l = Q[i].l-1;
		int r = Q[i].r-1;
		int k = Q[i].k;
		int y = ceil((float)(r-l+1)/k);
		if ((r-l+1)/k == y)
		y++;	
		while(mo_r < r)
		{
			mo_r++;
			T.add(arr[mo_r], y);
		}	
		while(mo_r > r)
		{
			T.remove(arr[mo_r], y);
			mo_r--;
		}	
		while(mo_l < l)
		{
			T.remove(arr[mo_l], y);
			mo_l++;
		}	
		while(mo_l > l)
		{
			mo_l--;
			T.add(arr[mo_l], y);
		}	
		if(!s.empty())
		{
			for(std::set<int>::iterator it=s.begin();it != s.end();it++)
			{
				
			}
		}	
		else ans[Q[i].id] = -1;	
	}	
	for(int i=0;i<q;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}