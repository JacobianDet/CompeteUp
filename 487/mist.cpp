#include <bits/stdc++.h>

std::string grid[40];

int main(void)
{
	int a,b,c,d;
	std::cin>>a>>b>>c>>d;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<50;j++)
		grid[i] += 'A';	
	}
	for(int i=10;i<20;i++)
	{
		for(int j=0;j<50;j++)
		grid[i] += 'B';	
	}	
	for(int i=20;i<30;i++)
	{
		for(int j=0;j<50;j++)
		grid[i] += 'C';	
	}	
	for(int i=30;i<40;i++)
	{
		for(int j=0;j<50;j++)
		grid[i] += 'D';	
	}	
	a--;
	b--;
	c--;
	d--;
	for(int i=0;i<10;i+=2)
	{
		for(int j=0;j<50;j+=2)
		{
			if(b)
			{	
				b--;
				grid[i][j] = 'B';
			}	
		}	
	}
	for(int i=10;i<20;i+=2)
	{
		for(int j=0;j<50;j+=2)
		{
			if(c)
			{
				c--;
				grid[i][j] = 'C';
			}	
		}	
	}
	for(int i=20;i<30;i+=2)
	{
		for(int j=0;j<50;j+=2)
		{
			if(d)
			{
				d--;
				grid[i][j] = 'D';
			}	
		}	
	}	
	for(int i=30;i<40;i+=2)
	{
		for(int j=0;j<50;j+=2)
		{
			if(a)
			{
				a--;
				grid[i][j] = 'A';
			}	
		}	
	}
	std::cout<<"40 50\n";
	for(int i=0;i<40;i++)
	{
		for(int j=0;j<50;j++)
		std::cout<<grid[i][j];
		std::cout<<"\n";	
	}	
	return 0;
}