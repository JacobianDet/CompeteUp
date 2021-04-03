#include <bits/stdc++.h>
#define ll long long
#define pb push_back

int main(void)
{
	int n,ctr=0;
	ll s1=0,s2=0;
	std::cin>>n;
	std::vector<int> a;
	if(n & 1)
	{
		for(int i=n;i>=2;i-=2,ctr++)
		{
			int x = i;
			int y = i-1;
			if(ctr & 1)
			{	
				a.pb(y);
				s1+=y;
				s2+=x;
			}	
			else 
			{
				a.pb(x);
				s1+=x;
				s2+=y;
			}		
		}	
		if(!(ctr & 1))
		{	
			s1+=1;
			a.pb(1);
		}
		else s2+=1;		
	}	
	else
	{
		for(int i=n;i>=1;i-=2,ctr++)
		{
			int x = i;
			int y = i-1;
			if(ctr & 1)
			{	
				a.pb(y);
				s1+=y;
				s2+=x;
			}	
			else 
			{	
				a.pb(x);
				s1+=x;
				s2+=y;
			}		
		}	
	}
	std::cout<<(ll)fabs(s2-s1)<<"\n"<<a.size()<<" ";
	for(int i=0,t=(int)a.size();i<t;i++)
	std::cout<<a[i]<<" ";
	return 0;	
}