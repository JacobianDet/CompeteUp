#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	ll sx = 0;
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i];
		sx += arr[i];
	}
	bool ok = 0;
	if(sx & 1)
	ok = 1;
	for(int i=0;i<n;i++)
	{
		if(arr[i] & 1)
		ok = 1;	
	}	
	if(ok)
	std::cout<<"first\n";
	else std::cout<<"second\n";
	return 0;	
}