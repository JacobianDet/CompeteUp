#include <bits/stdc++.h>
#define CHOR 10000001
#define pb push_back
typedef long long ll;

std::vector<ll> pr;
std::vector<bool> isP(CHOR, true);

void siever()
{
	isP[0] = 0;
	isP[1] = 0;
	for(ll i=2; i*i<=CHOR; i++)
	{
		if(isP[i])
		{
			for(ll p=i*i; p<CHOR; p+=i)
			isP[p] = 0;	
		}	
	}
	for(ll i=2;i<CHOR;i++)
	{
		if(isP[i])
		pr.pb(i);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	ll p,y;
	std::cin>>p>>y;
	ll i=y;
	bool flag = 0;
	for( ;i>1;i--)
	{
		flag = 0;
		for(ll j=0,k=(ll)pr.size();(j<k && pr[j]<=p);j++)
		{
			if(!(i%pr[j]))
			{
				flag = 1;
				break;
			}	
		}
		if(!flag)
		break;	
	}	
	if(i == 1 || i <= p)
	std::cout<<"-1\n";	
	else std::cout<<i<<"\n";
	return 0;
}