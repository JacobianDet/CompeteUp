#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back

typedef long long ll;

bool pmx[CHOR];

void siever(void)
{
	memset(pmx,1,sizeof(pmx));
	pmx[0] = 0;
	pmx[1] = 0;
	for(ll i=2;i*i<CHOR;i++)
	{
		if(pmx[i])
		{
			for(ll j=i*i;j<CHOR;j+=i)
			pmx[j] = 0;	
		}	
	}	
	return;
}

int main(void)
{
	siever();
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int arr[n];
		bool is1 = 0;
		for(int i=0;i<n;i++)
		{	
			std::cin>>arr[i];
			if(arr[i] == 1)
			is1 = 1;
		}
		if(is1)
		std::cout<<"0\n";
		else
		{		
			std::vector<int> sv;
			for(int i=0;i<n;i++)
			{
				if(pmx[arr[i]])
				sv.pb(arr[i]);	
			}	
			for(int i=0;i<n;i++)
			{
				if(!pmx[arr[i]])
				{
					bool ok = 1;
					for(int j=0,k=(int)sv.size();j<k;j++)
					{
						if(!(arr[i] % sv[j]))
						{	
							ok = 0;
							break;
						}		
					}	
					if(ok)
					sv.pb(arr[i]);	
				}	
			}
			if((int)sv.size() == 1)
			std::cout<<"-1\n";
			else std::cout<<(n-(int)sv.size())<<"\n";	
		}	
	}	
	return 0;
}