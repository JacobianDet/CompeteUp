#include <bits/stdc++.h>
#define ll long long

ll mep(ll x, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= x;
		x = x*x;
		n >>= 1;	
	}	
	return res;
}

ll dpal(ll i)
{
	ll z = 0,dig = 0,temp = i;
	while(temp)
	{
		z = 10*z + (temp%10);
		temp /= 10;
		dig++;
	}	
	temp = i*mep(10,dig) + z;
	return temp;
}

int main(void)
{
	ll k,p,sum=0;
	std::cin>>k>>p;
	for(ll i=1;i<=k;i++)
	sum = (sum%p + dpal(i)%p)%p;
	std::cout<<sum<<"\n";
	return 0;
}
