#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
	int n;
	ll m;
	std::cin>>n>>m;
	ll cpnote = 0;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		int pc = 0;
		ll z = arr[i];
		if(cpnote + z >= m)
		{
			pc++;
			z -= (m - cpnote);
			cpnote = 0;
		}	
		pc += (z/m);
		cpnote += (z%m);
		std::cout<<pc<<" ";
	}	
	std::cout<<"\n";
	return 0;
}