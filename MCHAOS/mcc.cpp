#include <bits/stdc++.h>
#define pb push_back
#define MV 100001

typedef long long ll;

ll BIT[MV];
std::map<std::string, int> cord;

struct cmp
{
	bool operator()(const std::string& str1, const std::string& str2)
	{
		return str1 < str2;
	}
};

class fentree
{
    public: void build(int n);
            void update(int i, int n);
            ll query(int i);
};

void fentree::build(int n)
{
    for(int i=1;i<=n;i++)
    BIT[i] = 0;
    return;
}

void fentree::update(int i, int n)
{
    for( ;i<=n;i+=(i & (-i)))
    BIT[i]++;
    return;
}

ll fentree::query(int i)
{
    ll sum = 0;
    for( ;i>0;i-=(i & (-i)))
    sum += BIT[i];
    return sum;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int n;
    std::cin>>n;
    std::set<std::string, cmp> s1;
    std::set<std::string, cmp> s2;
    for(int i=0;i<n;i++)
    {
        std::string s;
        std::cin>>s;
        s1.insert(s);
    }
    for(std::set<std::string, cmp>::iterator it = s1.begin();it != s1.end();it++)
    {
        std::string s = *it;
        std::reverse(s.begin(), s.end());
        s2.insert(s);
    }
    int x = 0;
    for(std::set<std::string, cmp>::iterator it = s2.begin();it != s2.end();it++)
    {
        x++;
        std::string s = *it;
        std::reverse(s.begin(), s.end());
        cord[s] = x;
    }
    ll ct = 0;
    fentree T;
    T.build(n);
    std::vector<int> Z;
    for(std::set<std::string, cmp>::iterator it = s1.begin();it != s1.end();it++)
    Z.pb(cord[*it]);
    for(int i=n-1;i>=0;i--)
    {
        ct += T.query(Z[i]-1);
        T.update(Z[i], n);
    }
    std::cout<<ct<<"\n";
    return 0;
}