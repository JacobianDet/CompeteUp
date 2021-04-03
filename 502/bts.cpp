#include <bits/stdc++.h>

typedef long long ll;

ll ctv[4];

int main(void)
{
	int n;
	std::cin>>n;
	std::string a, b;
	std::cin>>a>>b;
	for(int i=0;i<n;i++)
	{
		if(a[i] == '0' && b[i] == '0')
		ctv[0]++;
		else if(a[i] == '0' && b[i] == '1')
		ctv[1]++;
		else if(a[i] == '1' && b[i] == '0')
		ctv[2]++;
		else ctv[3]++;	
	}	
	ll ans = ctv[0]*(ctv[2] + ctv[3]) + ctv[1]*ctv[2];
	std::cout<<ans<<"\n";
	return 0;
}