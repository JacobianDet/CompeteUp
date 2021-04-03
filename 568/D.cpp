#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

std::vector<std::pair<int, int> > arr;

bool cmpx(std::pair<int, int> A, std::pair<int, int> B)
{
	return (A.first < B.first);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int z;
		std::cin>>z;
		arr.pb(mp(z, i));
	}	
	if(n == 2)
	std::cout<<arr[0].second + 1<<"\n";
	else
	{
		std::sort(arr.begin(), arr.end(), cmpx);
		std::vector<int> df;
		std::map<int, int> mx;
		for(int i=0;i<n-1;i++)
		{
			df.pb(arr[i+1].first - arr[i].first);
			mx[df[i]]++;
		}	
		if(mx.size() > 3)
		std::cout<<"-1\n";
		else
		{
			bool ok = 0;
			for(int i=0;i<n;i++)
			{
				if(!i)
				{	
					mx[df[i]]--;
					if(!mx[df[i]])
					mx.erase(df[i]);
					if(mx.size() == 1)
					{	
						ok = 1;
						std::cout<<arr[i].second + 1<<"\n";
						break;
					}
					mx[df[i]]++;
				}
				else if(i != n-1)
				{
					mx[df[i-1]]--;
					if(!mx[df[i-1]])
					mx.erase(df[i-1]);
					mx[df[i]]--;
					if(!mx[df[i]])
					mx.erase(df[i]);
					int nx = df[i] + df[i-1];
					mx[nx]++;
					if(mx.size() == 1)
					{
						ok = 1;
						std::cout<<arr[i].second + 1<<"\n";
						break;
					}	
					mx[nx]--;
					if(!mx[nx])
					mx.erase(nx);
					mx[df[i-1]]++;
					mx[df[i]]++;	
				}
				else
				{
					mx[df[i-1]]--;
					if(!mx[df[i-1]])
					mx.erase(df[i-1]);
					if(mx.size() == 1)
					{	
						ok = 1;
						std::cout<<arr[i].second + 1<<"\n";
						break;
					}
					mx[df[i-1]]++;
				}
			}
			if(!ok)
			std::cout<<"-1\n";	
		}	
	}
	return 0;	
}