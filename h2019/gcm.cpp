#include <bits/stdc++.h>

int main(void)
{
	std::string sx, vx[5];
	std::cin>>sx;
	for(int i=0;i<5;i++)
	std::cin>>vx[i];
	bool ok = 0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(sx[i] == vx[j][i])
			{
				ok = 1;
				break;
			}	
		} 
		if(ok)
		break;	
	}	
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}