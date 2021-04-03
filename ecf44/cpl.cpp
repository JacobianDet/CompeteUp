#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int p[n>>1];
	for(int i=0;i<(n>>1);i++)
	std::cin>>p[i];
	std::sort(p, p+(n>>1));
	int odd[n>>1], even[n>>1];
	int o = 1, e = 2;
	for(int i=0;i<(n>>1);i++)
	{
		odd[i] = o;
		even[i] = e;
		o+=2;
		e+=2;
	}
	o = 0, e = 0;
	for(int i=0;i<(n>>1);i++)
	{
		o += abs(p[i] - odd[i]);
		e += abs(p[i] - even[i]);
	}
	if(o < e)
	std::cout<<o<<"\n";
	else std::cout<<e<<"\n";	
	return 0;
}