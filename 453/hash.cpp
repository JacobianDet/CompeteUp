#include <bits/stdc++.h>

int main(void)
{
	int h;
	std::cin>>h;
	int a[h+1];
	for(int i=0;i<h+1;i++)
	std::cin>>a[i];
	int f=0;
	for(int i=0;i<h;i++)
	{
		if(a[i] != 1)
		f++;	
	}	
	if(!f)
	std::cout<<"perfect\n";
	else 
	{
		std::cout<<"ambiguous\n";
		int sz=0;
		for(int i=0;i<h+1;i++)
		sz += a[i];
		for(int i=1;i<=sz;i++)
		{
			
		}	
	return 0;	
}