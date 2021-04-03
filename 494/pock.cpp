#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int ctx[101];
	memset(ctx, 0, sizeof(ctx));
	for(int i=0;i<n;i++)
	{
		int a;
		std::cin>>a;
		ctx[a]++;
	}	
	int x = 0;
	for(int i=1;i<=100;i++)
	x = std::max(x, ctx[i]);
	std::cout<<x<<"\n";
	return 0;	
}