#include <bits/stdc++.h>

typedef long long ll;

std::string s[1001];
ll arr[1001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	for(int i=0;i<m;i++)
	std::cin>>arr[i];	
	ll res = 0;
	for(int i=0;i<m;i++)
	{
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		for(int j=0;j<n;j++)
		{
			if(s[j][i] == 'A')
			a++;
			else if(s[j][i] == 'B')
			b++;
			else if(s[j][i] == 'C')
			c++;
			else if(s[j][i] == 'D')
			d++;
			else e++;
		}
		int mx = std::max(a, std::max(b, std::max(c, std::max(d, e))));
		res += 1LL*mx*arr[i];
	}
	std::cout<<res<<"\n";
	return 0;
}	
