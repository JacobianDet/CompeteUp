#include <bits/stdc++.h>

using namespace std;

map<int, int> ctx;
int arr[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		cin>>arr[i];
		int p1 = 0, p2 = 0;
		std::map<int, int>::iterator it;
		int ans = 0;
		while(p2 < n)
		{
			if(ctx.size() == 1)
			{
				it = ctx.begin();
				if((arr[p2] > k) && (arr[p2] == it->first))
				{	
					ctx[arr[p2]]++;
					p2++;
				}	
				else if((arr[p2] > k) && (arr[p2] != it->first))
				{
					while(ctx[it->first])
					{
						if(arr[p1] == it->first)
						ctx[it->first]--;
						p1++;
					}
					ctx.erase(it->first);
					ctx[arr[p2]]++;
					p2++;
				}
				else p2++;	
				ans = max(ans, p2 - p1);
			}	
			else 
			{
				if((ctx.size() == 0) && (arr[p2] > k))
				{
					ctx[arr[p2]]++;
					p2++;
					ans = max(ans, p2 - p1);	
				}
				else p2++;	
			}
		}	
		while(p1 < n)
		{
			if(ctx.size() == 1)
			{	
				it = ctx.begin();
				if(arr[p1] == it->first)
				ctx[it->first]--;
				p1++;
				ans = max(ans, n - p1);	
			}
			else p1++;
		}
		cout<<ans<<"\n";
		ctx.clear();
	}
	return 0;
}