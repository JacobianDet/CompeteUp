#include <bits/stdc++.h>

int pref[41][41];
int memo[41][41][41][41];
std::string s[41];

int INEX(int a, int b, int c, int d)
{
	if(a > c || b > d)
	return 0;
	if(memo[a][b][c][d] != -1)
	return memo[a][b][c][d];
	int ans = (((pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1]) == ((c-a+1)*(d-b+1))) ? 1 : 0);
	ans += (INEX(a, b, c-1, d) + INEX(a, b, c, d-1) - INEX(a, b, c-1, d-1)) + (INEX(a+1, b, c, d) + INEX(a, b+1, c, d) - INEX(a+1, b+1, c, d)) - (INEX(a+1, b, c-1, d) + INEX(a+1, b, c, d-1) - INEX(a+1, b, c-1, d-1)) - (INEX(a, b+1, c-1, d) + INEX(a, b+1, c, d-1) - INEX(a, b+1, c-1, d-1)) + (INEX(a+1, b+1, c-1, d) + INEX(a+1, b+1, c, d-1) - INEX(a+1, b+1, c-1, d-1));	
	memo[a][b][c][d] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n,m,q;
	std::cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	std::cin>>s[i];	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j] == '0')
			pref[i+1][j+1] = 1;	
			pref[i+1][j+1] += pref[i+1][j];
		}	
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		pref[j][i] += pref[j-1][i];	
	}
	while(q--)
	{
		int a,b,c,d;
		std::cin>>a>>b>>c>>d;
		std::cout<<INEX(a, b, c, d)<<"\n";
	}
	return 0;
}