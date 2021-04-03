#include <bits/stdc++.h>
using namespace std;
#define MV 50001

typedef long long ll;

ll arr[MV], cst[MV], lid[MV];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		ll n,c;
		cin>>n>>c;
		arr[0] = 0;
		for(int i=1;i<=n;i++)
		cin>>arr[i];
		for(int i=0;i<n;i++)
		cin>>cst[i];
		stack<int> S;
		memset(lid, -1, sizeof(lid));
		for(int i=n-1;i>=0;i--)
		{
			if(S.empty())
			S.push(i);
			else
			{
				while(!S.empty() && (cst[S.top()] > cst[i]))
				S.pop();
				if(S.empty())
				lid[i] = -1;
				else lid[i] = S.top();
				S.push(i);	
			}	
		}
		ll fuel = 0, fill = 0, ans = 0;
		for(int i=0;i<n;fuel-=(arr[i+1]-arr[i]),i++)
		{
			ll x = 0;
			if(lid[i] == -1)
			x = arr[n] - arr[i];
			else x = arr[lid[i]] - arr[i];
			if(fuel >= x)
			fill = 0;
			else
			{
				if(c >= x)
				fill = x - fuel;
				else fill = c - fuel;	
			}	
			fuel += fill;
			ans += (fill * cst[i]);
		}	
		cout<<ans<<"\n";
	}
	return 0;
}