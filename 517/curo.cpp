#include <bits/stdc++.h>

int a[100001], b[100001], t[100001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	std::cin>>a[i];
	for(int i=0;i<n-1;i++)
	std::cin>>b[i];
	bool xok = 1;
	for(int x=0;x<4;x++)
	{
		memset(t, 0, sizeof(t));
		t[0] = x;
		bool ok = 1;
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<2;j++)
			{
				if((t[i] & (1<<j)) && (a[i] & (1<<j)) && (b[i] & (1<<j)))
				t[i+1] |= (1<<j);
				else if((t[i] & (1<<j)) && (a[i] & (1<<j)) && !(b[i] & (1<<j)))
				continue;
				else if(!(t[i] & (1<<j)) && (a[i] & (1<<j)) && !(b[i] & (1<<j)))
				t[i+1] |= (1<<j);
				else if(!(t[i] & (1<<j)) && !(a[i] & (1<<j)) && !(b[i] & (1<<j)))
				continue;	
				else 
				{
					ok = 0;
					break;
				}
			}
			if(!ok)
			break;	
		}
		if(ok)
		{	
			xok = 1;
			break;
		}	
		else xok = 0;
	}
	if(!xok)
	std::cout<<"NO\n";
	else 
	{
		std::cout<<"YES\n";
		for(int i=0;i<n;i++)
		std::cout<<t[i]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}