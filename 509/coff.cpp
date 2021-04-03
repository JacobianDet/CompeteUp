#include <bits/stdc++.h>
#define mp std::make_pair

int dayv[200001];
std::map<int, int> cord;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,d;
	std::cin>>n>>m>>d;
	std::set<int> Z;
	for(int i=0;i<n;i++)
	{
		int x;
		std::cin>>x;
		Z.insert(x);
		cord[x] = i;
	}	
	int dx = 0;
	while(!Z.empty())
	{
		dx++;
		int z = *Z.begin();
		Z.erase(Z.begin());
		dayv[cord[z]] = dx;
		std::set<int>::iterator it;
		while(!Z.empty() && ((z + d + 1) <= m) && ((it = Z.lower_bound(z + d + 1)) != Z.end()))
		{
			z = *it;
			Z.erase(it);
			dayv[cord[z]] = dx;
		}	
	}
	std::cout<<dx<<"\n";
	for(int i=0;i<n;i++)
	std::cout<<dayv[i]<<" ";
	std::cout<<"\n";
	return 0;	
}
