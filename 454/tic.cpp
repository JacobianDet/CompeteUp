#include <bits/stdc++.h>

char grid[10][10];

int main(void)
{
	memset(grid,'.',sizeof(grid));
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++)
		std::cin>>grid[i][j];		
	}
	int x,y;
	std::cin>>x>>y;
	int flag = 0;
	if((x == 1 || x == 4 || x == 7) && (y == 1 || y == 4 || y == 7))
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 1 || x == 4 || x == 7) && (y == 2 || y == 5 || y == 8))
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=4;j<=6;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 1 || x == 4 || x == 7) && (y == 3 || y == 6 || y == 9))
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=7;j<=9;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 2 || x == 5 || x == 8) && (y == 1 || y == 4 || y == 7))
	{
		for(int i=4;i<=6;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 2 || x == 5 || x == 8) && (y == 2 || y == 5 || y == 8))
	{
		for(int i=4;i<=6;i++)
		{
			for(int j=4;j<=6;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 2 || x == 5 || x == 8) && (y == 3 || y == 6 || y == 9))
	{
		for(int i=4;i<=6;i++)
		{
			for(int j=7;j<=9;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 3 || x == 6 || x == 9) && (y == 1 || y == 4 || y == 7))
	{
		for(int i=7;i<=9;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 3 || x == 6 || x == 9) && (y == 2 || y == 5 || y == 8))
	{
		for(int i=7;i<=9;i++)
		{
			for(int j=4;j<=6;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	else if((x == 3 || x == 6 || x == 9) && (y == 3 || y == 6 || y == 9))
	{
		for(int i=7;i<=9;i++)
		{
			for(int j=7;j<=9;j++)
			{
				if(grid[i][j] == '.')
				{
					flag++;
					grid[i][j] = '!';
				}	
			}	
		}	
	}	
	if(!flag)
	{
		for(int i=1;i<10;i++)
		{
			for(int j=1;j<10;j++)
			{
				if(grid[i][j] == '.')
				grid[i][j] = '!';	
			}	
		}	
	}
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++)
		{	
			std::cout<<grid[i][j];
			if(j == 3 || j == 6)
			std::cout<<" ";
		}
		if(i == 3 || i == 6)
		std::cout<<"\n";		
		std::cout<<"\n";
	}
	return 0;
}	