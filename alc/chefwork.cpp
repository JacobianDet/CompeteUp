#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	int ct[n];
	int tp[n];
	for(int i=0;i<n;i++)
	std::cin>>ct[i];
	for(int i=0;i<n;i++)
	std::cin>>tp[i];
	std::vector<int> v[4];
	for(int i=0;i<n;i++)
	v[tp[i]].pb(ct[i]);
	for(int i=1;i<4;i++)
	std::sort(v[i].begin(), v[i].end());
	if(!v[1].empty() && !v[2].empty() && !v[3].empty())
	std::cout<<std::min(v[1][0] + v[2][0], v[3][0])<<"\n";
	else if(!v[1].empty() && !v[2].empty())
	std::cout<<v[1][0] + v[2][0]<<"\n";	
	else if(!v[3].empty())
	std::cout<<v[3][0]<<"\n";
	return 0;	
}