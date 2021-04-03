#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

//SOURCE CODE TAKEN FROM CHOTA

int arr[200001];
int par[200001];
int memo[200001];
std::pair<int, int> bval[200001];

bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
	if(a.first < b.first)
	return 1;
	else if ((a.first == b.first) && (a.second < b.second))
	return 1;
	else return 0;	
}

void bsearch(int a, int ind, int n)
{
	int lo = 0;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if((bval[mid].first > a) || ((bval[mid].first == a) && (bval[mid].second > ind)))
		hi = mid - 1;
		else lo = mid;	
	}	
	if((bval[lo].first == a) && (bval[lo].second < ind))
	{
		par[ind] = bval[lo].second;
		memo[ind] = 1 + memo[bval[lo].second];
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{	
		memo[i] = 1;
		par[i] = i;
	}	
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
		bval[i] = mp(arr[i], i);
	}	
	std::sort(bval, bval+n, cmp);
	for(int i=0;i<n;i++)
	bsearch(arr[i]-1, i, n-1);
	int p = 0;
	for(int i=0;i<n;i++)
	{
		if(memo[p] < memo[i])
		p = i;	
	}
	std::cout<<memo[p]<<"\n";
	std::vector<int> res;
	while(p != par[p])
	{
		res.pb(p+1);
		p = par[p];
	}	
	res.pb(p+1);
	std::reverse(res.begin(), res.end());
	for(int i=0,j=(int)res.size();i<j;i++)
	std::cout<<res[i]<<" ";
	std::cout<<"\n";
	/*for(int i=0;i<n;i++)
	std::cout<<memo[i]<<" ";
	std::cout<<"\n";*/	
	return 0;	
}