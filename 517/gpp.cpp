#include <bits/stdc++.h>

int main(void)
{
	int w,h,k;
	std::cin>>w>>h>>k;
	int tot = 0;
	for(int i=1;i<=k;i++)
	tot += (2*(w - 4*(i-1)) + 2*(h - 4*(i-1) - 2));
	std::cout<<tot<<"\n";
	return 0;
}