#include <bits/stdc++.h>

typedef long long ll;

std::string s[1001];
ll axp[1001][1001], memo[1001][1001];
int n;

ll MR0X(int i, int j)
{
	if(i == n)
   	return 0;
	if(memo[i][j] != -1)
	return memo[i][j];
	ll ans = 0;
	if(!axp[j][i])
	ans = std::max(MR0X(i+1, j), MR0X(i+1, i+1));
	else ans = std::max(MR0X(i+1, j, sl), std::max(axp[j][i] + MR0X(i+1, i+1),  MR0X(i+1, i+1)));
	memo[i][j] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(memo, -1, sizeof(memo));
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>s[i];
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int p1 = s[i].size()-1;
				int p2 = s[j].size()-1;
				int cl = 0;
				while((p1 >= 0) && (p2 >= 0) && (s[i][p1] == s[j][p2]))
				{
					cl++;
					p1--;
					p2--;
				}	
				axp[i][j] = cl;
			}
		}
		ll ans = MR0X(0, 0, 0);
		std::cout<<"Case #"<<t<<": "<<ans<<"\n";	
	}
	return 0;
}