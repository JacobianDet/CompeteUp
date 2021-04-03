#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::string sv[11];
int lcp[200001];
int rig[100001];
std::vector<std::pair<int, int> > Z;

bool cmpx(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}

int main(void)
{
	std::string s;
	std::cin>>s;
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>sv[i];
	for(int x=0;x<n;x++)
	{
		std::string z = sv[x] + '#' + s;
		for(int i=1,m=(int)z.size();i<m;i++)
		{
			int j = lcp[i-1];
			while(j && (z[i] != z[j]))
			j = lcp[j-1];
			if(z[i] == z[j])
			j++;
			lcp[i] = j;
			if(lcp[i] == (int)sv[x].size())
			Z.pb(mp(i-2*((int)sv[x].size()), i-((int)sv[x].size() + 1)));
		}	
	}	
	for(int i=0,j=(int)s.size();i<j;i++)
	rig[i] = j;	
	for(int i=0,j=(int)Z.size();i<j;i++)
	{	
		//std::cout<<Z[i].first<<" "<<Z[i].second<<"\n";
		rig[Z[i].first] = std::min(rig[Z[i].first], Z[i].second);
	}	
	for(int i=(int)s.size()-2;i>=0;i--)
	rig[i] = std::min(rig[i], rig[i+1]);
	int maxx = 0, pos = 0;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		//std::cout<<i<<" "<<rig[i]<<"\n";
		if(rig[i] - i > maxx)
		{
			maxx = rig[i] - i;
			pos = i;
		}	
	}	
	std::cout<<maxx<<" "<<pos<<"\n";
	return 0;
}