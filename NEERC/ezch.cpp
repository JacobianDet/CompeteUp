#include <bits/stdc++.h>
#define INF 10000001

int memo[9][9][64];
int par[9][9][64];

int chessboy(int r, int c, int rmv)
{
	if(r == 1 && c == 1)
	{
		if(rmv == 1)
		return 0;
		else return INF;	
	}
	else if(rmv <= 0)
	return INF;	
	if(memo[r][c][rmv] != -1)
	return memo[r][c][rmv];
		
}

int main(void)
{
	int n;
	std::cin>>n;

}