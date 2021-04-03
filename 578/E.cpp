#include <bits/stdc++.h>

typedef long long ll;

std::string s[100001];
int lcp[1000001];

int KMP(std::string &s1, std::string &s2)
{
	std::string z = s1 + '#' + s2;
	lcp[0] = 0;
	for(int i=1;i<(int)z.size();i++)
	{
		int j = lcp[i-1];
		while(j && (z[i] != z[j]))
		j = lcp[j-1];
		if(z[i] == z[j])
		j++;
		lcp[i] = j;	
	}
	return lcp[(int)z.size()-1];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	std::string res = s[0];
	for(int i=1;i<n;i++)
	{
		int ml = std::min(res.size(), s[i].size());
		std::string t = s[i].substr(0, ml);
		std::string u = res.substr((int)res.size()-ml, ml);
		int vx = KMP(t, u);
		for(int j=vx;j<s[i].size();j++)
		res += s[i][j];	
	}
	std::cout<<res<<"\n";
	return 0;
}		