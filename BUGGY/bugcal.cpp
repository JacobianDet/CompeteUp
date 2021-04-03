#include <bits/stdc++.h>

void arrcov(long long z, std::vector<int> &t)
{
	for(int i=0;i<11;i++)
	{
		t[i] = z%10;
		z /= 10;
	}
}

int main(void)
{
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++)
	{
		long long a,b,ans=0;
		std::cin>>a>>b;
		std::vector<int> x(11);
		std::vector<int> y(11);
		std::vector<int> res(11);
		arrcov(a, x);
		arrcov(b, y);
		for(int j=10;j>=0;j--)
		res[j] = (x[10-j] + y[10-j])%10;
		for(int j=0;j<11;j++)
		ans = 10*ans + res[j];
		std::cout<<ans<<"\n";
	}
	return 0;
}

