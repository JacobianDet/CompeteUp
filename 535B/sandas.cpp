#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int temp = n;
	int dig = 0;
	while(temp)
	{
		dig++;
		temp /= 10;
	}	
	int pos = 0;
	for(int i=0;i<(1 << dig);i++)
	{
		temp = 0;
		for(int j=dig-1;j>=0;j--)
		{
			if(i & (1 << j))
			temp = ((1 << 3) + (1 << 1))*temp + 7;
			else temp = ((1 << 3) + (1 << 1))*temp + 4;	
		}	
		if(temp == n)
		{
			pos = i - 1+ (1 << dig);
			break;
		}	
	}	
	std::cout<<pos<<"\n";
	return 0;
}