#include <bits/stdc++.h>

std::string s,t;
int n1, n2;
int pref[200001], suff[200001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin>>s>>t;
    n1 = s.size();
    n2 = t.size();
    int lt = 0;
    for(int i=0;i<n1;i++)
    {
    	if(lt == n2)
    	pref[i] = lt;	
    	else if(s[i] == t[lt])
    	pref[i] = ++lt;
    	else pref[i] = (i-1 != -1) ? pref[i-1] : 0;	
    }	
    lt = n2-1;
    int ct = 0;
    for(int i=n1-1;i>=0;i--)
    {
    	if(ct == n2)
    	suff[i] = ct;
    	else if(s[i] == t[lt])
    	{	
    		lt--;
    		suff[i] = ++ct;
    	}	
    	else suff[i] = (i+1 < n1) ? suff[i+1] : 0;	
    }
    int res = 0;
    int p1 = 0, p2 = 0;
    while(p1 < n1)
    {
    	int px = (p2-1 != -1) ? pref[p2-1] : 0;
    	int sx = (p1+1 < n1) ? suff[p1+1] : 0;
    	//std::cout<<px<<" "<<sx<<" "<<p1<<" "<<p2<<"\n";
    	if(px + sx >= n2)
    	{	
    		res = std::max(res, (p1-p2+1));
    		p1++;
    	}	
    	else
    	{
    		if(p1 == p2)
    		{
    			p1++;
    			p2++;
    		}	
    		else p2++;
    	}
    }
    p1 = n1-1;
    while(p2 < n1)
    {
    	int px = (p2-1 != -1) ? pref[p2-1] : 0;
    	int sx = (p1+1 < n1) ? suff[p1+1] : 0;
    	//std::cout<<px<<" "<<sx<<" "<<p1<<" "<<p2<<"\n";
    	if(px + sx >= n2)
    	res = std::max(res, (p1-p2+1));
    	p2++;
    }
    std::cout<<res<<"\n";
    return 0;
}    