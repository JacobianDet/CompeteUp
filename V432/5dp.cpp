#include <bits/stdc++.h>
#define pb push_back

struct fivept
{
	int a,b,c,d,e;
}arr[1001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d>>arr[i].e;
	if(n > 100)
	std::cout<<"0\n";
	else
	{
		std::vector<int> Z;
		for(int i=0;i<n;i++)
		{
			bool ok = 1;
			for(int j=0;j<n;j++)
			{
				if(j != i)
				{
					for(int k=0;k<n;k++)
					{
						if((k != i) && (k != j))
						{
							int z = (arr[k].a - arr[i].a) * (arr[j].a - arr[i].a) + (arr[k].b - arr[i].b) * (arr[j].b - arr[i].b) + (arr[k].c - arr[i].c) * (arr[j].c - arr[i].c) + (arr[k].d - arr[i].d) * (arr[j].d - arr[i].d) + (arr[k].e - arr[i].e) * (arr[j].e - arr[i].e);
							if(z > 0)
							{
								ok = 0;
								break;
							}	
						}	
					}
					if(!ok)
					break;	
				}
			}
			if(ok)
			Z.pb(i+1);	
		}		std::cout<<(int)Z.size()<<"\n";
		for(int i=0,j=(int)Z.size();i<j;i++)
		std::cout<<Z[i]<<"\n";	
	}	
	return 0;
}