#include <bits/stdc++.h>

int main(void)
{
	int x;
	std::cin>>x;
	int a=0,b=0;
	bool ok = 0;
	for(a=1;a<=x;a++)
	{
		for(b=1;b<=a;b++)
		{
			if(!(a % b) && (a * b > x) && (a/b < x))
			{
				ok = 1;
				break;
			}
		}
		if(ok)
		break;	
	}	
	if(ok)
	std::cout<<a<<" "<<b<<"\n";
	else std::cout<<"-1\n";
	return 0;	
}