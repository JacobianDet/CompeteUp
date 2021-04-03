#include <bits/stdc++.h>

int main(void)
{
	bool flag = 0;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			if(i*i + j*j == (1000 - i - j)*(1000 - i - j))
			{
				flag = 1;
				std::cout<<i*j*(1000 - i - j)<<"\n";
				break;
			}	
		}
		if(flag)
		break;	
	}
	return 0;	
}