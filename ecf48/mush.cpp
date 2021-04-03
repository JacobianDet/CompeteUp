#include <bits/stdc++.h>

typedef long long ll;

ll prefi[2][300001], prefd[2][300001], prefx[2][300001], arr[2][300001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=n;j++)
		std::cin>>arr[i][j];	
	}
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			prefi[i][j] = prefi[i][j-1] + j*arr[i][j];
			prefd[i][j] = prefd[i][j-1] + (n-j+1)*arr[i][j];
			prefx[i][j] = prefx[i][j-1] + arr[i][j];
		}		
	}
	ll ans = 0, xd = 0;
	for(int i=0,j=1;j<=n;++j,i^=1)
	{
		ll ax = xd + (prefi[i][n] - prefi[i][j-1]) + (j-1)*(prefx[i][n] - prefx[i][j-1]) + (prefd[i^1][n] - prefd[i^1][j-1]) + (n+j-1)*(prefx[i^1][n] - prefx[i^1][j-1]);
		ans = std::max(ans, ax);
		xd += ((2*j)-1)*arr[i][j] + (2*j)*arr[i^1][j];
	}
	for(int i=1;i<=n;i++)
	ans -= (arr[0][i] + arr[1][i]);	
	std::cout<<ans<<"\n";
	return 0;
}