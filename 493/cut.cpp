#include <bits/stdc++.h>

int memo[101][101][101];
int po[101], pe[101], arr[101];
int n;

int cutx(int i, int j, int b)
{
	if(b < 0)
	return -10000;
	else if(i == n)
	return 0;
	if(memo[i][j][b] != -1)
	return memo[i][j][b];	
	int ans = 0;
	if((po[i] - po[j]) == (pe[i] - pe[j]))
	ans = std::max(ans, std::max(1 + cutx(i+1, i, b-abs(arr[i+1]-arr[i])), cutx(i+1, j, b)));
	else ans = cutx(i+1, j, b);
	memo[i][j][b] = ans;
	return ans;	
}

int main(void)
{
	memset(memo, -1, sizeof(memo));
	int b;
	std::cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		std::cin>>arr[i];
		if(arr[i] & 1)
		{
			po[i] = po[i-1] + 1;
			pe[i] = pe[i-1];
		}	
		else
		{
			po[i] = po[i-1];
			pe[i] = pe[i-1] + 1;
		}
	}
	int ans = cutx(1, 0, b);
	std::cout<<ans<<"\n";
	return 0;	
}