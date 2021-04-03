#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 200001

typedef long long ll;

ll arr[CHOR];
int rem[CHOR], c[CHOR];
std::vector<int> gre;
std::set<int> les;

int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	int n,m;
	n = readInt();
	m = readInt();
	int q = n/m;
	std::set<std::pair<ll, int> > idx[m];
	for(int i=0;i<n;i++)
	{	
		arr[i] = readInt();
		rem[i] = arr[i]%m;
		c[rem[i]]++;
	}
	for(int i=0;i<m;i++)
	{
		if(c[i] > q)
		gre.pb(i);
		else if(c[i] < q)
		les.insert(i);	
	}	
	ll ctx = 0;
	for(int i=0,j=(int)gre.size();i<j;i++)
	{
		while(c[gre[i]] > q)
		{
			bool allm = 0;
			std::set<int>::iterator it = les.upper_bound(gre[i]);
			if(it == les.end())
			allm = 1;
			if(allm)
			it = les.begin();
			int z = c[gre[i]] - q;
			int y = q - c[*it];
			if(y > z)
			{
				c[gre[i]] = q;
				c[*it] += z;
				ll diff = 0;
				if(!allm)
				diff = (1LL*(*it) - gre[i]);
				else diff = (1LL*m + (*it) - gre[i]);
				ctx += z*diff;
				idx[gre[i]].insert(mp(diff, z));

			}
			else
			{
				c[*it] = q;
				c[gre[i]] -= y;
				ll diff = 0;
				if(!allm)
				diff = (1LL*(*it) - gre[i]);
				else diff = (1LL*m + (*it) - gre[i]);
				ctx += y*diff;
				idx[gre[i]].insert(mp(diff, y));
				les.erase(it);
			}	
		}	
	}
	std::cout<<ctx<<"\n";
	for(int i=0;i<n;i++)
	{
		std::pair<ll, int> p;
		if((int)idx[rem[i]].size())
		{
			p = *idx[rem[i]].begin();
			arr[i] += p.first;
			p.second--;
			idx[rem[i]].erase(idx[rem[i]].begin());
			if(p.second)
			idx[rem[i]].insert(p);
		}
		std::cout<<arr[i]<<" ";
	}
	std::cout<<"\n";	
	return 0;	
}