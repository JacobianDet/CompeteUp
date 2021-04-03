#include <bits/stdc++.h>

int arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{	
		std::cin>>arr[i];
		arr[i] += arr[i-1];
	}	
	int q;
	std::cin>>q;
	while(q--)
	{
		int l,r;
		std::cin>>l>>r;
		std::cout<<(arr[r] - arr[l-1])/10<<"\n";
	}
	return 0;
}