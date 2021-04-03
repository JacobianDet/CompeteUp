#include <bits/stdc++.h>

typedef long long ll;

ll fx[100001], sx[100002];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	for(int i=1;i<=n;i++)
	std::cin>>fx[i];
	for(int i=1;i<=n;i++)
	sx[i] = sx[i-1] ^ fx[i];
	sx[n+1] = 0;
	while(q--)
	{
		int px;
		std::cin>>px;
		px %= (n+1);
		if(!px)
		px += (n+1);
		std::cout<<sx[px]<<"\n";	
	}	
	return 0;	
}