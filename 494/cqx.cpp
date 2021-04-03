#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::map<ll, int> mcx;
std::map<ll, int> mas;
std::vector<ll> arr;

int bs2(ll y, int a, int b)
{
	int lo = a;
	int hi = b;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(arr[mid] > y)
		hi = mid - 1;
		else lo = mid;	
	}	
	if((lo <= hi) && (arr[lo] <= y))
	return lo;
	else return -1;	
}

int main(void)
{
	int n,q;
	std::cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		ll t;
		std::cin>>t;
		if(mcx[t])
		mcx[t]++;
		else
		{
			arr.pb(t);
			mcx[t]++;
		}	
	}
	std::sort(arr.begin(), arr.end());
	while(q--)
	{
		ll t;
		std::cin>>t;
		if(mas[t])
		std::cout<<mas[t]<<"\n";
		else
		{	
			ll z = t;
			int lo = 0;
			int hi = (int)arr.size()-1;
			ll ans = 0;
			while(z)
			{
				int p = bs2(z, lo, hi);
				if(p != -1)
				{
					ll m = z/arr[p];
					ll cm = mcx[arr[p]];
					if(cm > m)
					{
						z -= m*arr[p];
						ans += m;
						hi = p-1;
					}	
					else
					{
						z -= cm*arr[p];
						ans += cm;
						hi = p-1;
					}	
				}
				else
				{
					ans = -1;
					break;
				}	
			}
			mas[t] = ans;
			std::cout<<ans<<"\n";
		}		
	}	
	return 0;
}