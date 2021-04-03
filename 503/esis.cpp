#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

struct pol2
{
	int can;
	ll bout;
}arr[3001];

int pvote[3001];
std::vector<int> part;
std::vector<pol2> Z;
std::multiset<ll> vot[3001];

bool cmp(pol2 u, pol2 v)
{
	return (u.bout < v.bout);
}

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	int mv = 0;
	for(int i=1;i<=n;i++)
	{
		std::cin>>arr[i].can>>arr[i].bout;
		vot[arr[i].can].insert(arr[i].bout);
		pvote[arr[i].can]++;
	}	
	for(int i=1;i<=m;i++)
	{
		if(pvote[i] > mv)
		{
			mv = pvote[i];
			part.clear();
			part.pb(i);
		}
		else if(pvote[i] == mv)
		part.pb(i);
	}	
	if(((int)part.size() == 1) && (part[0] == 1))
	std::cout<<"0\n";
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(arr[i].can != 1)
			Z.pb(arr[i]);	
		}
		std::sort(Z.begin(), Z.end(), cmp);

	}	

}