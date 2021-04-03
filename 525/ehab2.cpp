#include <bits/stdc++.h>
#define CHOR 100000

int arr[2001];	

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		std::cin>>arr[i];
		arr[i] += CHOR;
	}
	std::cout<<n<<"\n";
	std::cout<<"1 "<<n<<" "<<CHOR<<"\n";
	for(int i=1;i<n;i++)
	std::cout<<"2 "<<i<<" "<<arr[i]-i<<"\n";
	return 0;	
}