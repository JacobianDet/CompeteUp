#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++)
	{
		int w;
		std::string s;
		std::cin>>w>>s;
		int arr[7];
		memset(arr,0,sizeof(arr));
		int z = 0;
		if(s == "mon")
		z = 0;
		else if(s == "tues")
		z = 1;
		else if(s == "wed")
		z = 2;
		else if(s == "thurs")
		z = 3;
		else if(s == "fri")
		z = 4;
		else if(s == "sat")
		z = 5;
		else if(s == "sun")
		z = 6;
		for(int j=1;j<=w;j++)
		{
			arr[z]++;
			z = (z+1)%7;
		}
		for(int j=0;j<7;j++)
		std::cout<<arr[j]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}