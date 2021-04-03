#include <bits/stdc++.h>

std::map<int, int> ctz;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
    	int x;
    	std::cin>>x;
    	ctz[x]++;
    }
    std::set<int> V;
    for(auto u : ctz)
    {
    	if(u.second > 0 && u.first != 1 && V.find(u.first-1) == V.end()) {V.insert(u.first-1); --u.second;}
    	if(u.second > 0 && V.find(u.first) == V.end()) {V.insert(u.first); --u.second;}
    	if(u.second > 0) {V.insert(u.first + 1); --u.second;}
    }
    std::cout<<V.size()<<"\n";
    return 0;
}    	