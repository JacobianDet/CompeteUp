#include <bits/stdc++.h>

std::string G[120];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>G[i];
	int x = -1, y = -1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(G[i][j] == 'B')
			{
				x = i;
				y = j;
				break;
			}	
		}
		if(x != -1)
		break;	
	}	
	int ln = 0;
	for(int i=0;i<n;i++)
	{
		if(x+i >= n || G[x+i][y] == 'W')
		break;
		else ln++;	
	}
	ln = (ln>>1) + 1;
	std::cout<<x + ln<<" "<<y + ln<<"\n";
	return 0;
}