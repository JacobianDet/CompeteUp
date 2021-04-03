#include <bits/stdc++.h>

typedef long long ll;

int arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::multiset<int> Z;
	for(int i=0;i<n;i++)
	Z.insert(arr[i]);
	ll tcut = 0, curvc = 0;
	for(int i=0;i<k;i++)
	{
		if(!Z.empty())
		{
			int z = *Z.begin();
			Z.erase(Z.begin());
			std::cout<<z - tcut<<"\n";
			tcut += (z - tcut);
			while(!Z.empty())
			{
				int vx = *Z.begin();
				if(vx == tcut)
				Z.erase(Z.begin());
				else break;
			}	
		}
		else std::cout<<"0\n";
	}
	return 0;	
}