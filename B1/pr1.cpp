#include <bits/stdc++.h>
#define pb push_back

std::string s[101];
int lnr[101][10001], rnr[101][10001];
std::vector<int> Z;

int bs1(int val)
{
	int lo = 0;
	int hi = (int)Z.size()-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(Z[mid] < val)
		lo = mid + 1;
		else hi = mid;	
	}
	if((lo <= hi) && (Z[lo] >= val))
	return lo;
	else return -1;
}

int bs2(int val)
{
	int lo = 0;
	int hi = (int)Z.size()-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(Z[mid] <= val)
		lo = mid;
		else hi = mid - 1;	
	}
	if((lo <= hi) && (Z[lo] <= val))
	return lo;
	else return -1;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		int ct = 0;
		for(int j=0;j<m;j++)
		{
			if(s[i][j] == '0')
			ct++;	
		}	
		if(ct == m)
		{
			ok = 0;
			break;
		}
	}	
	if(!ok)
	std::cout<<"-1\n";
	else
	{
		memset(lnr, -1, sizeof(lnr));
		memset(rnr, -1, sizeof(rnr));
		for(int i=0;i<n;i++)
		{
			Z.clear();
			for(int j=0;j<m;j++)
			{
				if(s[i][j] == '1')
				{
					Z.pb(j);
					lnr[i][j] = j;
					rnr[i][j] = j;
				}	
			}
			for(int j=0;j<m;j++)
			{
				if(s[i][j] != '1')
				{
					int px = bs2(j);
					if(px != -1)
					lnr[i][j] = Z[px];
					else lnr[i][j] = Z[(int)Z.size()-1];
					int py = bs1(j);
					if(py != -1)
					rnr[i][j] = Z[py];
					else rnr[i][j] = Z[0];
				}	
			}	
		}
		int ans = 100000000;
		for(int i=0;i<m;i++)
		{
			int ians = 0;
			for(int j=0;j<n;j++)
			{
				if(s[j][i] != '1')
				ians += std::min(((lnr[j][i] > i) ? (m - lnr[j][i] + i) : (i - lnr[j][i])), ((rnr[j][i] < i) ? (rnr[j][i] + m - i) : (rnr[j][i] - i)));
			}
			ans = std::min(ans, ians);	
		}
		std::cout<<ans<<"\n";
	}	
	return 0;
}