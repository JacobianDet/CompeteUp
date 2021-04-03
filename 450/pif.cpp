#include <bits/stdc++.h>
#define MAX 100000000

int main(void)
{
	int a,b,c,flag = 1;
	std::cin>>a>>b>>c;
	for(int i=1;i<=MAX;i++)
	{
		int q = (a*10)/b;
		if(q == c)
		{
			std::cout<<i<<"\n";
			flag = 0;
			break;
		}	
		a = (a*10)%b;
	}
	if(flag == 1)
	std::cout<<-1<<"\n";
	return 0;	
}