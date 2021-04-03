#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[101];

int main(void)
{
	int n,s;
	std::cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		int x,y;
		std::cin>>x>>y;
		arr[i] = mp(x, y);
	}	
	int ah = -1, am = -1;
	for(int i=0;i<n;i++)
	{
		if(!i)
		{
			int v = arr[i].first*60 + arr[i].second;
			if((v - s - 1) >= 0)
			{	
				ah = 0, am = 0;
				break;
			}	
		}
		else
		{
			int v = ((arr[i].first) * 60) + arr[i].second;
			int vx = ((arr[i-1].first) * 60) + arr[i-1].second;
			if((v - s - 1) >= (vx + s + 1))
			{
				ah = (vx + s + 1)/60;
				am = (vx + s + 1) - (ah*60);
				break;
			}	
		}
	}
	if(ah == -1)
	{
		int v = arr[n-1].first*60 + arr[n-1].second;
		ah = (v + s + 1)/60;
		am = (v + s + 1) - (ah*60);
	}
	std::cout<<ah<<" "<<am<<"\n";
	return 0;
}