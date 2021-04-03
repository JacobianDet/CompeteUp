#include <bits/stdc++.h>
#define pb push_back

struct cmpx
{
	bool operator()(const std::string& str1, const std::string& str2)
	{
		return (str1 < str2);
	}
};

std::multiset<std::string, cmpx> X;
std::vector<std::string> arr;
std::vector<std::vector<int> > memo;
int m, n;

int kach(int i, int len)
{
    if(i == n)
    return 0;
    if(memo[i][len] != -1)
    return memo[i][len];
    int ans = 10000000;
    bool f = 0;
    for(int j=1;j<=len;j++)
    {
        if(!i)
        ans = std::min(ans, j + kach(i+1, j));
        else if(arr[i][j-1] != arr[i-1][j-1])
        ans = std::min(ans, j + kach(i+1, j));
    } 
    if((int)arr[i].size() > len)
    ans = std::min(ans, len+1 + kach(i+1, len+1));
    memo[i][len] = ans;
    return ans;   
}

int main(void)
{
    std::cin>>n;
    memo.resize(n+5);
    m = 0;
    for(int i=0;i<n;i++)
    {
        std::string s;
        m = std::max(m, (int)s.size());
        std::cin>>s;
        X.insert(s);
    }
    for(int i=0;i<n;i++)
    memo[i].resize(m+5, -1);
    std::vector<std::string> A(X.begin(), X.end());
    arr = A;
    int ans = kach(0, (int)arr[0].size());
    std::cout<<ans<<"\n";
    return 0;
}