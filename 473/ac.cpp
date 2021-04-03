#include <bits/stdc++.h>
#define CHOR 10000001

int primex[CHOR];
bool apr[CHOR];

void siever(void)
{
	for(int i=0;i<CHOR;i++)
	{	
		primex[i] = i;
		apr[i] = 1;
	}	
	for(int i=2;i*i<=CHOR;i++)
	{
		if(primex[i] == i)
		{	
			for(int p=i*i;p<CHOR;p+=i)
			primex[p] = i;
		}		
	}
	return;
}

int main(void)
{
	siever();
	int n;
	std::cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::set<int> pinc;
	bool flag = 1;
	for(int i=0;i<n; )
	{
		std::set<int> Z;
		int t = arr[i];
		while(t != 1)
		{
			if(pinc.find(primex[t]) != pinc.end())
			{
				flag = 0;
				break;
			}	
			int p = primex[t];
			Z.insert(p);
			while(primex[t] == p)
			t /= primex[t];
		}	
		if(flag)
		{	
			for(std::set<int>::iterator it=Z.begin();it != Z.end();it++)
			pinc.insert(*it);	
			std::cout<<arr[i]<<" ";
			i++;
		}		
		else
		{
			for(std::set<int>::iterator it = pinc.begin();it != pinc.end();it++)
			{
				int j = *it;
				for(int k=j;k<CHOR;k+=j)
				apr[k] = 0;
			}	
			t = arr[i]+1;
			for(int j=t;j<CHOR;j++)
			{
				if(apr[j])
				{
					for(int k=j;k<CHOR;k+=j)
					apr[k] = 0;
					std::cout<<j<<" ";
					t = j;
					i++;
					break;
				}
			}
			Z.clear();
			while(t != 1)
			{
				Z.insert(primex[t]);
				t /= primex[t];
			}	
			for(std::set<int>::iterator it = Z.begin();it != Z.end();it++)
			{
				int j = *it;
				for(int k=j;k<CHOR;k+=j)
				apr[k] = 0;
			}	
			for(int j=2;((j<CHOR) && (i<n));j++)
			{
				if(apr[j])
				{
					for(int k=j;k<CHOR;k+=j)
					apr[k] = 0;
					std::cout<<j<<" ";
					i++;
				}
			}	
		}	
	}
	std::cout<<"\n";
	return 0;	
}