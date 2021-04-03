#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> Q[100001];
int arr[100002], zx[100002][2];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(zx, 0, sizeof(zx));
		memset(arr, 0, sizeof(arr));
		int n,k;
		std::cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int l,r;
			std::cin>>l>>r;
			arr[l]++;
			arr[r+1]--;
			Q[i] = mp(l, r);
		}
		for(int i=2;i<=100000;i++)
		arr[i] += arr[i-1];
		for(int i=1;i<=100000;i++)
		{
			if(arr[i] == k)
			zx[i][0]++;
			if(arr[i] == k+1)
			zx[i][1]++;
			zx[i][0] += zx[i-1][0];
			zx[i][1] += zx[i-1][1];	
		}
		int ov = 0;
		for(int i=1;i<=n;i++)
		ov = std::max(ov, zx[100000][0] - (zx[Q[i].second][0] - zx[Q[i].first-1][0]) + (zx[Q[i].second][1] - zx[Q[i].first-1][1]));
		std::cout<<ov<<"\n";
	}
	return 0;
}