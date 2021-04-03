#include <bits/stdc++.h>
#define ll long long
#define CHOR 1000000

std::vector<int> vals(2*CHOR + 1);
std::vector<ll> cols(2*CHOR + 1);
std::vector<ll> grid(CHOR + 1);

void calci(void)
{
	for(int i=2;i<=2*CHOR;i++)
	{
		int temp = i,odd = 0,even = 0;
		while(temp)
		{
			if((temp % 10) & 1)
			odd += (temp % 10);
			else even += (temp % 10);
			temp /= 10;	
		}		
		vals[i] = fabs(odd-even);
		cols[i] = cols[i-1]+vals[i];
	}
	grid[1] = cols[2];
	for(int i=4;i<=2*CHOR;i+=2)
	grid[i/2] = grid[i/2-1] + 2*(cols[i]-cols[i/2]) - vals[i];
	vals.clear();
	cols.clear();
	return;
}

int main(void)
{
	calci();
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++)
	{
		int n;
		std::cin>>n;
		std::cout<<grid[n]<<"\n";
	}
	return 0;
}
