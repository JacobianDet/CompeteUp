#include <bits/stdc++.h>

int lcp[2000001];
std::string s;

int bs2(int n, int k)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		std::string t = s.substr(0, mid);
		std::reverse(t.begin(), t.end());
		std::string z = t + '#' + s;
		for(int i=1;i<=n+mid;i++)
		{
			int j = lcp[i-1];
			while(j && (z[i] != z[j]))
			j = lcp[j-1];
			if(z[i] == z[j])
			j++;
			lcp[i] = j;	
		}	
		int ct = 0;
		for(int i=mid+1;i<=n+mid;i++)
		{
			if(lcp[i] == mid)
			ct++;	
		}
		if(ct >= k)
		lo = mid;
		else hi = mid - 1;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int k;
	std::cin>>s>>k;
	int n = (int)s.size();
	int ans = bs2(n, k);
	std::cout<<ans<<"\n";
	return 0;
}