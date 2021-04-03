#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		std::string a;
		std::cin>>a;
		std::string x;
		std::vector<int> V;
		V.pb(0);
		for(int i=1,j=(int)a.size();i<j;i++)
		{
			if(a[i] == a[0])
			V.pb(i);
		}
		bool ok1 = 0;
		bool ok2 = 0;
		if((int)V.size() > 1)
		{
			x = a.substr(V[0], V[1]-V[0]);
			ok1 = 1;
		}
		if(ok1)
		{	
			for(int i=0,j=(int)V.size();i<j;i++)
			{
				if(i != j-1)
				{	
					if(a.substr(V[i], V[i+1]-V[i]) != x)
					{
						ok2 = 1;
						break;
					}
				}
				else if((i == j-1) && (V[i] != (int)a.size()-1))
				{
					if(a.substr(V[i], (int)a.size()-V[i]) != x)
					{
						ok2 = 1;
						break;
					}	
				}		
			}
		}
		std::cout<<"Case #"<<t<<": ";
		if(!ok2)
		std::cout<<"Impossible\n";
		else std::cout<<(x + a)<<"\n";	
	}	
	return 0;
}