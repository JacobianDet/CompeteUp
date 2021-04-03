#include <bits/stdc++.h>

typedef long long ll;

ll nok[101];

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		t %= k;
		nok[t]++;
	}	
	ll ax = 0;
	for(int i=1;i<=k/2;i++)
	{	
		if(!(k & 1) && (i == k/2))
		ax += nok[i]/2;	
		else ax += std::min(nok[i], nok[k-i]);
	}	
	ax += nok[0]/2;
	std::cout<<ax*2<<"\n";
	return 0;
}