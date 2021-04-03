#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::multiset<int> X;
std::vector<int> zx;

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		zx.pb(t);
		X.insert(t);
	}	
	int ct = 0;
	std::sort(zx.begin(), zx.end());
	for(int i=0;i<n;i++)
	{
		std::multiset<int>::iterator it = X.lower_bound(zx[i]);
		X.erase(it);
		for(int j=0;j<32;j++)
		{
			ll v = (1LL<<j);
			if(v <= zx[i])
			continue;
			else
			{
				it = X.lower_bound(v - 1LL*zx[i]);
				if((it == X.end()) || (*it != v-1LL*zx[i]))
				continue;
				else 
				{
					ct++;
					break;
				} 	
			}	
		}
		X.insert(zx[i]);	
	}	
	std::cout<<n-ct<<"\n";
	return 0;
}