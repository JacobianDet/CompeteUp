#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	std::string s;
	std::cin>>s;
	int freq1[26], freq2[26];
	memset(freq1, 0, sizeof(freq1));
	memset(freq2, 0, sizeof(freq2));
	for(int i=0;i<n;i++)
	freq1[s[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		if(freq1[i] >= k)
		{
			freq2[i] = k;
			k = 0;
			break;
		}	
		else
		{
			freq2[i] = freq1[i];
			k -= freq1[i];
		}	
	}
	for(int i=0;i<n;i++)
	{
		if(freq2[s[i]-'a'])
		freq2[s[i]-'a']--;
		else std::cout<<s[i];	
	}	
	std::cout<<"\n";
	return 0;
}