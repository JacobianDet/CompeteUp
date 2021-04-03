#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	std::vector<int> Z;
	for(int i=1;i<1e8;i++)
	{
		int temp = i, sum = 0;
		while(temp)
		{
			sum += (temp % 10);
			temp /= 10;
		}	
		if(sum == 10)
		Z.pb(i);	
	}
	int k;
	std::cin>>k;
	std::cout<<Z[k-1]<<"\n";
	return 0;
}