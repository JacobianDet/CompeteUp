#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 100001

std::pair<int, int> arr[CHOR];
int col[CHOR], dx[CHOR];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		std::cin>>x>>y;
		arr[i] = mp(x, y);
	}
	for(int i=1;i<=n;i++)
	std::cin>>col[i];
	int tc = 0;
	for(int i=0;i<n-1;i++)
	{
		if(col[arr[i].first] != col[arr[i].second])
		{
			tc++;
			dx[arr[i].first]++;
			dx[arr[i].second]++;
		}	
	}	
	bool ok = 0;
	for(int i=1;i<=n;i++)
	{
		if(dx[i] == tc)
		{
			std::cout<<"YES\n"<<i<<"\n";
			ok = 1;
			break;
		}
	}
	if(!ok)
	std::cout<<"NO\n";
	return 0;	
}