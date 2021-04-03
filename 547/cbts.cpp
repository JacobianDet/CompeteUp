#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<int> va[27];
std::vector<int> vb[27];
bool ua[150001], ub[150001];
std::vector<std::pair<int, int> > res;

int main(void)
{
	int n;
	std::cin>>n;
	std::string s1, s2;
	std::cin>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		if(s1[i] == '?')
		va[26].pb(i);
		else va[s1[i] - 'a'].pb(i);	
	}	
	for(int i=0;i<n;i++)
	{
		if(s2[i] == '?')
		vb[26].pb(i);
		else vb[s2[i] - 'a'].pb(i);	
	}
	int mpx = 0;
	for(int i=0;i<27;i++)
	{
		int j=0;
		if(i < 26)
		{
			while(j < std::min(va[i].size(), vb[i].size()))
			{
				ua[va[i][j]] = 1;
				ub[vb[i][j]] = 1;
				mpx++;
				res.pb(mp(va[i][j]+1, vb[i][j]+1));
				j++;
			}
		}	
		else
		{
			for(int k=0;k<26;k++)
			{
				int t = 0;
				while((t < vb[k].size()) && (j < va[i].size()))
				{
					if(!ub[vb[k][t]])
					{
						ua[va[i][j]] = 1;
						ub[vb[k][t]] = 1;
						mpx++;
						res.pb(mp(va[i][j]+1, vb[k][t]+1));
						j++;
						t++;
					}
					else t++;	
				}	
			}	
			j = 0;
			for(int k=0;k<26;k++)
			{
				int t = 0;
				while((t < va[k].size()) && (j < vb[i].size()))
				{
					if(!ua[va[k][t]])
					{
						ua[va[k][t]] = 1;
						ub[vb[i][j]] = 1;
						mpx++;
						res.pb(mp(va[k][t]+1, vb[i][j]+1));
						j++;
						t++;
					}
					else t++;	
				}
			}
			j = 0;
			int j1 = 0, j2 = 0;
			while((j1 < va[26].size()) && (j2 < vb[26].size()))
			{
				if(!ua[va[26][j1]] && !ub[vb[26][j2]])
				{
					ua[va[26][j1]] = 1;
					ub[vb[26][j2]] = 1;
					mpx++;
					res.pb(mp(va[26][j1] + 1, vb[26][j2] + 1));
					j1++;
					j2++;
				}
				else if(!ua[va[26][j1]])
				j2++;
				else if(!ub[vb[26][j2]])
				j1++;
				else
				{
					j1++;
					j2++;
				}	
			}		
		}
	}
	std::cout<<mpx<<"\n";
	for(int i=0;i<mpx;i++)
	std::cout<<res[i].first<<" "<<res[i].second<<"\n";
	return 0;	
}