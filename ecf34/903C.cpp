#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	std::sort(a,a+n);	
	int ctr1=1,ctrm=1;
	for(int i=1;i<n;i++)
	{
		if(a[i] == a[i-1])
		ctr1++;
		else{
			ctrm = std::max(ctrm,ctr1);
			ctr1 = 1;
		}	
	}	
	ctrm = std::max(ctrm,ctr1);
	std::cout<<ctrm<<"\n";
	return 0;
}