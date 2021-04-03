
#include <bits/stdc++.h>

int main(void)
{
	int a = 1,b = 1,n = 0;
	std::cin>>n;
	std::string res;
	for(int i=0;i<n;i++)
	res += 'o';
	while(a <= n)
	{
		int temp = b;
		b += a;
		a = temp;
		res[a-1] = 'O';
	}
	std::cout<<res<<"\n";
	return 0;
}
