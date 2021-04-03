#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000000];

ll val(ll n)
{
	if(n<1000000)
		return dp[n];
	else
		return max(n,val(n/2)+val(n/3)+val(n/4));
}

int main()
{
	ll n,i;
	for(i=0;i<1000000;i++)
	{
		if(i<=10)
			dp[i]=i;
		else
			dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
	}
	while(!cin.eof())
	{
		cin>>n;
		cout<<val(n)<<endl;
	}
}
