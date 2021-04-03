#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll mn[70];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>mn[i];
		std::sort(mn, mn+n);
		ll ax = 1;
		for(int i=0;i<n;i++)
		{
			if((mn[i] - i) <= 0)
			{
				ax = 0;
				break;
			}	
			else ax = ((ax%MOD) * ((mn[i]%MOD) - (i%MOD) + MOD))%MOD;
		}
		std::cout<<ax<<"\n";	
	}
	std::cout<<"KILL BATMAN\n";
	return 0;
}