#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100000

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main(void)
{
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++)
	{
		std::vector<int> z(CHOR+1); 
        std::vector<int> ing(CHOR+1);
		int n,ct[3];
		memset(ct,0,sizeof(ct));
		std::cin>>n;
		std::vector<int> a(n);
		std::vector<int> x;
		for(int j=0;j<n;j++)
		{	
			std::cin>>a[j];
			z[a[j]]++;
		}
		for(int j=1;j<=CHOR;j++)
		{
			if(z[j] == 1)
			ct[1]++;
			else if(z[j] == 2)
			{				
				ct[2]++;
				x.pb(j);
			}	
		}
		if(x.size() != 0)
		{	
			for(int j=1,k=x.size();j<k;j++)
			ing[x[j-1]] = x[j];
			ing[x[x.size()-1]] = x[0];
		}	
		if(ct[1] == 0 && ct[2] == 1)
		{
			std::cout<<0<<"\n";
			for(int j=0;j<n;j++)
			std::cout<<a[j]<<" ";
			std::cout<<"\n";	
		}	
		else if(ct[1] == 1 && ct[2] == 0)
		{
			std::cout<<0<<"\n";
			for(int j=0;j<n;j++)
			std::cout<<a[j]<<" ";
			std::cout<<"\n";	
		}	
		else if(ct[1] == 1 && ct[2] == 1)
		{
			std::cout<<2<<"\n";
			for(int j=1;j<n;j++)
			std::cout<<a[j]<<" ";
			std::cout<<a[0]<<"\n";	
		}		
		else if(ct[1] > 1 && ct[2] == 1)
		{
			std::cout<<n<<"\n";
			int pos1=-1,pos2=-1;
			for(int j=0;j<n;j++)
			{
				if(ing[a[j]] != 0)
				{
					if(pos1 == -1)
					pos1 = j;
					else pos2 = j;	
				}	
			}	
			if(pos1 == 0 && pos2 == n-1)
			{
				swap(a[pos2],a[pos2-2]);
				std::cout<<a[n-1]<<" ";
				for(int j=0;j<n-1;j++)
				std::cout<<a[j]<<" ";
				std::cout<<"\n";	
			}	
			else if(pos1 + 1 == pos2)
			{
				if(pos1 >= 2)
				swap(a[pos1],a[pos1-2]);	
				else swap(a[pos1],a[pos2+1]);
				std::cout<<a[n-1]<<" ";
				for(int j=0;j<n-1;j++)
				std::cout<<a[j]<<" ";
				std::cout<<"\n";	
			}	
			else
			{
				for(int j=1;j<n;j++)
				std::cout<<a[j]<<" ";
				std::cout<<a[0]<<"\n";	
			}	
		}	
		else if(ct[2] > 1 && ct[1] == 1)
		{
			std::cout<<n<<"\n";
			int pos1=-1,pos2=-1;
			for(int j=0;j<n;j++)
			{
				if(z[a[j]] == 1)
				pos1 = j;
				else if(z[a[j]] == 2)
				pos2 = j;
				if(pos1 != -1 && pos2 != -1)
				break;	
			}
			swap(a[pos1],a[pos2]);
			for(int j=0;j<n;j++)
			{
				if(ing[a[j]] != 0)
				std::cout<<ing[a[j]]<<" ";
				else std::cout<<a[j]<<" ";	
			}	
			std::cout<<"\n";	
		}	
		else
		{
			std::cout<<n<<"\n";
			x.clear();
			for(int j=0;j<n;j++)
			{
				if(z[a[j]] == 1)
				x.pb(a[j]);	
			}	
			int k=1;
			for(int j=0;j<n;j++)
			{
				if(ing[a[j]] != 0)
				std::cout<<ing[a[j]]<<" ";
				else
				{
					if(k == x.size())
					k = 0;
					std::cout<<x[k]<<" ";
					k++;	
				}	
			}
			std::cout<<"\n";	
		}	
	}	
	return 0;
}