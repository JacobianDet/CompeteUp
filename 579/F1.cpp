#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

std::vector<std::pair<int, int> > V1, V2;

bool cmpx(std::pair<int, int> A, std::pair<int, int> B)
{
	return (A.first + A.second > B.first + B.second);
}

int memo[101][30001];

int BALLIA(int t, int r)
{
	if(r < 0)
	return -100000;
	else if(t == (int)V2.size())
	return 0;
	if(memo[t][r] != -1)
	return memo[t][r];
	int ans = 0;
	if(V2[t].first <= r)
	ans = std::max(BALLIA(t+1, r), 1 + BALLIA(t+1, r+V2[t].second));
	else ans = BALLIA(t+1, r);
	memo[t][r] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    int n,r;
    std::cin>>n>>r;
    for(int i=0;i<n;i++)
    {
    	int rx, cx;
    	std::cin>>rx>>cx;
    	if(cx >= 0)
    	V1.pb(mp(rx, cx));
    	else V2.pb(mp(rx, cx));		
    }	
    std::sort(V1.begin(), V1.end());
    std::sort(V2.begin(), V2.end(), cmpx);
    int ct = 0;
    for(auto u : V1)
    {
    	if(u.first <= r)
    	{
    		ct++;
    		r += u.second;
    	}		
    }
    ct += BALLIA(0, r);
	std::cout<<ct<<"\n";
    return 0;	
}