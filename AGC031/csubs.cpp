#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll ctr[26];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	for(int i=0;i<n;i++)
	ctr[s[i] - 'a']++;
	ll ans = 1;
	for(int i=0;i<26;i++)
	ans = ((ans%MOD) * (((ctr[i]%MOD) + (1%MOD))%MOD))%MOD;
	ans = ((ans%MOD) - (1%MOD) + MOD)%MOD;
	std::cout<<ans<<"\n";
	return 0;	
}