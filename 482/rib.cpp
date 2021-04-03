#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n;
	std::cin>>n;
	std::string s[3];
	for(ll i=0;i<3;i++)
	std::cin>>s[i];
	ll maxct[3];
	memset(maxct,0,sizeof(maxct));
	for(ll i=0;i<3;i++)
	{
		ll ctr[52];
		memset(ctr,0,sizeof(ctr));
		for(ll j=0,k=(ll)s[i].size();j<k;j++)
		{
			if(s[i][j] >= 'A' && s[i][j] <= 'Z')
			ctr[(s[i][j] - 65) + 26]++;
			else ctr[(s[i][j] - 97)]++;
		}
		for(ll j=0;j<52;j++)
		maxct[i] = std::max(maxct[i], ctr[j]);
	}	
	ll x = (ll)s[0].size();
	if(n == 1 && ((maxct[0] == x) || (maxct[1] == x) || (maxct[2] == x)))
	{
		if((maxct[0] == x) && (maxct[1] == x) && (maxct[2] == x))
		{
			maxct[0]--;
			maxct[1]--;
			maxct[2]--;
		}	
		else if((maxct[0] == x) && (maxct[1] == x))
		{
			maxct[0]--;
			maxct[1]--;
			maxct[2]++;
		}	
		else if((maxct[0] == x) && (maxct[2] == x))
		{
			maxct[0]--;
			maxct[2]--;
			maxct[1]++;
		}	
		else if((maxct[2] == x) && (maxct[1] == x))
		{
			maxct[2]--;
			maxct[1]--;
			maxct[0]++;
		}	
		else if(maxct[0] == x)
		{
			maxct[0]--;
			maxct[1]++;
			maxct[2]++;
		}	
		else if(maxct[1] == x)
		{
			maxct[1]--;
			maxct[0]++;
			maxct[2]++;
		}	
		else if(maxct[2] == x)
		{
			maxct[2]--;
			maxct[1]++;
			maxct[0]++;
		}	
		ll omaxx = std::max(maxct[0], std::max(maxct[1], maxct[2]));
		if(((omaxx == maxct[0]) && (omaxx == maxct[1])) || ((omaxx == maxct[0]) && (omaxx == maxct[2])) || ((omaxx == maxct[2]) && (omaxx == maxct[1])))
		std::cout<<"Draw\n";
		else if(omaxx == maxct[0])
		std::cout<<"Kuro\n";
		else if(omaxx == maxct[1])
		std::cout<<"Shiro\n";
		else std::cout<<"Katie\n";	
	}	
	else if(((maxct[0] < (x - n)) && (maxct[1] < (x - n)) && (maxct[2] < (x - n))) || ((maxct[0] >= (x - n)) && (maxct[1] < (x - n)) && (maxct[2] < (x - n))) || ((maxct[0] < (x - n)) && (maxct[1] >= (x - n)) && (maxct[2] < (x - n))) || ((maxct[0] < (x - n)) && (maxct[1] < (x - n)) && (maxct[2] >= (x - n))))
	{	
		ll omaxx = std::max(maxct[0], std::max(maxct[1], maxct[2]));
		if(((omaxx == maxct[0]) && (omaxx == maxct[1])) || ((omaxx == maxct[0]) && (omaxx == maxct[2])) || ((omaxx == maxct[2]) && (omaxx == maxct[1])))
		std::cout<<"Draw\n";
		else if(omaxx == maxct[0])
		std::cout<<"Kuro\n";
		else if(omaxx == maxct[1])
		std::cout<<"Shiro\n";
		else std::cout<<"Katie\n";	
	}	
	else std::cout<<"Draw\n";
	return 0;
}