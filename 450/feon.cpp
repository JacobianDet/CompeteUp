#include <bits/stdc++.h>
#define mp std::make_pair 

int main(void)
{
	int n;
	std::cin>>n;
	std::pair<int, int> crd[n];
	for(int i=0;i<n;i++)
	{
		int x=0,y=0;
		std::cin>>x>>y;
		crd[i] = mp(x,y);
	}	
	int cn = 0,cp = 0;
	for(int i=0;i<n;i++)
	{
		if(crd[i].first > 0)
		cp++;
		else cn++;	
	}	
	if((cp == n && cn == 0) || (cp == n-1 && cn == 1) || (cn == n && cp == 0) || (cn == n-1 && cp == 1))
	std::cout<<"Yes\n";
	else std::cout<<"No\n";
	return 0;	
}