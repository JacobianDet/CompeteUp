#include <bits/stdc++.h>
#define CHOR 34001
#define pb push_back

std::vector<int> vfx;
bool mark[CHOR];

void siever(void)
{
	memset(mark,1,sizeof(mark));
	mark[0] = 0;
	mark[1] = 0;
	for(int i=2;i<CHOR;i++)
	{
		if(mark[i])
		{
			vfx.pb(i);
			int ctr = 0;
			for(int j=i+1;j<CHOR;j++)
			{
				while((j<CHOR) && !mark[j])
				j++;	
				if((j<CHOR) && mark[j])
				ctr++;
				if(!(ctr % i))
				{
					mark[j] = 0;
					ctr = 0;
				}	
			}	
		}	
	}
	return;	
}

int main(void)
{
	siever();
	int n;
	std::cin>>n;
	while(n)
	{
		std::cout<<vfx[n-1]<<"\n";
		std::cin>>n;
	}	
	return 0;
}