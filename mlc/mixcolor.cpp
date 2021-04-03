#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		std::vector<int> arr(n);
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		std::sort(arr.begin(), arr.end());
		int t = 0;
		for(int i=0;i<n; )
		{
			if(arr[i] == arr[n-1])
			{	
				t += n-1-i;
				i = n;
			}	
			else 
			{
				std::vector<int>::iterator it = std::upper_bound(arr.begin(), arr.end(), arr[i]);
				t += (it - arr.begin() - 1 - i);
				i = (it - arr.begin()); 
			}	
		}
		std::cout<<t<<"\n";	
	}	
	return 0;
}