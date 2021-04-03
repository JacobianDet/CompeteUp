#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

int ctr1[26], ctr2[26];
std::vector<int> fpx[101];
std::pair<int, int> memo[101][101];
bool vis[101][101];

int bs1(int id, int vx)
{
	int lo = 0;
	int hi = (int)fpx[id].size()-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(fpx[id][mid] > vx)
		hi = mid;
		else lo = mid + 1;
	}
	if((lo > hi) || (fpx[id][lo] <= vx))
	return fpx[id][0];
	else return fpx[id][lo];
}	

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(vis, 0, sizeof(vis));
	int p1, p2;
	std::cin>>p1>>p2;
	std::string s1, s2;
	std::cin>>s1>>s2;
	int n1 = (int)s1.size(), n2 = (int)s2.size();
	for(int i=0;i<n1;i++)
	ctr1[s1[i] - 'a']++;
	for(int i=0;i<n2;i++)
	ctr2[s2[i] - 'a']++;
	bool ok = 1;
	for(int i=0;i<26;i++)
	{
		if(!ctr1[i] && ctr2[i])
		{
			ok = 0;
			break;
		}
	}
	if(ok)
	{
		for(int i=0;i<n2;i++)
		{
			for(int j=0;j<n1;j++)
			{
				if(s1[j] == s2[i])
				fpx[i].pb(j);
			}
		}
		int cs = 0;
		int id = 0, ppos = fpx[0][0], ix = 1;
		while(ix <= p1)
		{	
			if(vis[id][ppos])
			{
				int sc = cs - memo[id][ppos].second;
				int ixd = ix - memo[id][ppos].first;
				for( ;(ix + ixd) <= p1;ix += ixd)
				cs += sc;
				int nid = ((id < n2 - 1) ? id + 1 : 0);
			        int pos = bs1(nid, ppos);
			        if(pos <= ppos)
			        ix++;
				if(!nid)
				cs++;	
				id = nid;
				ppos = pos;
				break;		
			}	
			vis[id][ppos] = 1;
			memo[id][ppos] = mp(ix, cs);		
			int nid = ((id < n2 - 1) ? id + 1 : 0);
			int pos = bs1(nid, ppos);
			if(pos <= ppos)
			ix++;
			if(!nid)
			cs++;	
			id = nid;
			ppos = pos;		
		}
		while(ix <= p1)
		{
			int nid = ((id < n2 - 1) ? id + 1 : 0);
			int pos = bs1(nid, ppos);
			if(pos <= ppos)
			ix++;
			if(!nid)
			cs++;	
			id = nid;
			ppos = pos;
		}				
		std::cout<<(cs/p2)<<"\n";
	}
	else std::cout<<"0\n";
	return 0;
}	
